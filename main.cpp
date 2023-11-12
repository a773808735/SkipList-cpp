#include <iostream>
#include "skiplist.h"
#define FILE_PATH "./store/dumpFile"

int main()
{

    SkipList<int, std::string> skipList(6);
    skipList.insert_element(1, "a");
    skipList.insert_element(3, "b");
    skipList.insert_element(7, "c");
    skipList.insert_element(8, "d");
    skipList.insert_element(9, "e");
    skipList.insert_element(19, "f");
    skipList.insert_element(19, "g");
    std::cout << "skipList size:" << skipList.size() << std::endl;
    skipList.search_element(9);
    skipList.search_element(18);
    skipList.display_list();
    skipList.search_element(9);
    skipList.search_element(18);

    skipList.delete_element(3);
    skipList.delete_element(7);
    skipList.display_list();
    std::cout << "skipList size:" << skipList.size() << std::endl;
    return 0;
}