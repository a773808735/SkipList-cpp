#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <mutex>
#include <fstream>

#define STORE_FILE "store/dumpFile"
std::mutex mux;
std::string delimiter = ":";

// Class template for Node
template <typename K, typename V>
class Node
{
public:
    Node() {}
    Node(K k, V v, int);
    ~Node();
    K get_key() const { return key_; }
    V get_value() const { return value_; }
    void set_value(V);
    Node<K, V> **forward;
    int node_level;

private:
    K key_;
    V value_;
};

template <typename K, typename V>
class SkipList
{
public:
    SkipList(int);
    ~SkipList();
    int get_random_level();
    Node<K, V> *create_node(K, V, int);
    int insert_element(K, V);
    void display_list();
    bool search_element(K);
    void delete_element(K);
    void dump_file();
    void load_file();
    int size() { return element_count_; }

private:
    void get_key_value_from_string(const std::string &str, std::string *key, std::string *value);
    bool is_valid_string(const std::string &str);
    int max_level_;
    int skip_list_level_;
    Node<K, V> *header_;
    std::ofstream file_writer_;
    std::ifstream file_reader_;
    int element_count_;
};

#include "skiplist.h"

/*
 *Definition of the function of nodes
 */
template <typename K, typename V>
Node<K, V>::Node(K k, V v, int level)
{
    this->key_ = k;
    this->node_level = level;
    this->value_ = v;
    this->forward = new Node<K, V> *[level + 1];
    memset(this->forward, 0, sizeof(Node<K, V> *) * (level + 1));
}

template <typename K, typename V>
Node<K, V>::~Node()
{
    delete[] forward;
}
template <typename K, typename V>
void Node<K, V>::set_value(V val)
{
    this->value_ = val;
}

template <typename K, typename V>
SkipList<K, V>::SkipList(int level)
{
    this->max_level_ = level;
    this->skip_list_level_ = 0;
    this->element_count_ = 0;
    K k = K{};
    V v = V{};
    this->header_ = new Node<K, V>(k, v, max_level_);
}

// bug??
template <typename K, typename V>
SkipList<K, V>::~SkipList()
{
    if (file_reader_.is_open())
    {
        file_reader_.close();
    }
    if (file_writer_.is_open())
    {
        file_writer_.close();
    }
    auto head = header_;
    while (head != nullptr)
    {
        auto cur = head->forward[0];
        delete head;
        head = cur;
    }
}

template <typename K, typename V>
int SkipList<K, V>::get_random_level()
{
    int k = 1;
    while (rand() % 2 && k < this->max_level_)
    {
        k++;
    }
    return k;
}

template <typename K, typename V>
Node<K, V> *SkipList<K, V>::create_node(K k, V v, int level)
{
    return new Node<K, V>(k, v, level);
}

template <typename K, typename V>
int SkipList<K, V>::insert_element(K k, V v)
{
    mux.lock();
    Node<K, V> *current = this->header_;
    Node<K, V> *update[max_level_ + 1];
    memset(update, 0, sizeof(Node<K, V> *) * (max_level_ + 1));
    for (int i = skip_list_level_; i >= 0; --i)
    {
        while (current->forward[i] != nullptr && current->forward[i]->get_key() < k)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current != nullptr && current->get_key() == k)
    {
        std::cout << "key: " << k << ", already exists" << std::endl;
        mux.unlock();
        return 1;
    }
    else
    {
        element_count_++;
        int random_level = this->get_random_level();
        if (random_level > this->skip_list_level_)
        {
            for (int i = skip_list_level_; i <= random_level; ++i)
            {
                update[i] = header_;
            }
            this->skip_list_level_ = random_level;
        }
        Node<K, V> *insert_node = create_node(k, v, random_level);
        for (int i = 0; i <= random_level; i++)
        {
            insert_node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = insert_node;
        }
        std::cout << "Successfully inserted key:" << k << ", value " << v << std::endl;
    }
    mux.unlock();
    return 0;
}
template <typename K, typename V>
bool SkipList<K, V>::search_element(K key)
{
    Node<K, V> *cur = this->header_;
    for (int i = skip_list_level_; i >= 0; --i)
    {
        while (cur->forward[i] != nullptr)
        {
            if (cur->forward[i]->get_key() == key)
            {
                return true;
            }
            else if (cur->forward[i]->get_key() > key)
            {
                break;
            }
            else
                cur = cur->forward[i];
        }
    }
    return false;
}

template <typename K, typename V>
void SkipList<K, V>::display_list()
{
    std::cout << "----SkipList----" << std::endl;
    for (int i = skip_list_level_; i >= 0; --i)
    {
        Node<K, V> *cur = this->header_->forward[i];
        std::cout << "Level " << i << ": ";
        while (cur != nullptr)
        {
            std::cout << "key is: " << cur->get_key() << " value is: " << cur->get_value();
            cur = cur->forward[i];
        }
        std::cout << std::endl;
    }
}

template <typename K, typename V>
void SkipList<K, V>::delete_element(K key)
{
    mux.lock();
    Node<K, V> *cur = this->header_;
    Node<K, V> *update[this->skip_list_level_ + 1];
    memset(update, 0, sizeof(Node<K, V> *) * (this->skip_list_level_ + 1));
    for (int i = this->skip_list_level_; i >= 0; --i)
    {
        while (cur->forward[i] != nullptr && cur->forward[i]->get_key() < key)
        {
            cur = cur->forward[i];
        }
        update[i] = cur;
    }
    cur = cur->forward[0];
    if (cur != nullptr && cur->get_key() == key)
    {
        for (int i = 0; i < this->skip_list_level_; ++i)
        {
            if (update[i]->forward[i] != cur)
                break;
            update[i]->forward[i] = cur->forward[i];
        }
        while (skip_list_level_ && header_->forward[skip_list_level_] == 0)
        {
            skip_list_level_--;
        }
        element_count_--;
    }
    mux.unlock();
    return;
}