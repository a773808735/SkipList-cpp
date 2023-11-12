cmake_minimum_required(VERSION 3.0.0)
project(tiaobiao VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include_directories(./include)
enable_testing()
add_library(MyLibrary SHARED skiplist.cpp)
target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(skiplist main.cpp)
target_link_libraries(skiplist PRIVATE MyLibrary)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
