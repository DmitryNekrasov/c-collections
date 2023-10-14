cmake_minimum_required(VERSION 3.26)
project(c-collections C)

set(CMAKE_C_STANDARD 11)

add_executable(c-collections main.c
        string.h
        string.c
        hash_map.h
        hash_map.c
        constants.h
        src/ArrayList/array_list_internal.h
        src/ArrayList/array_list_internal.c
        src/ArrayList/array_list.h
        CuTest/CuTest.h
        CuTest/CuTest.c
        test/ArrayListSuite.c
        src/Queue/queue.h
        src/Queue/queue_internal.h
        src/Queue/queue_internal.cpp)
