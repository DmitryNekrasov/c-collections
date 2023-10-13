cmake_minimum_required(VERSION 3.26)
project(hash_map C)

set(CMAKE_C_STANDARD 11)

add_executable(hash_map main.c
        string.h
        string.c
        hash_map.h
        hash_map.c
        constants.h
        ArrayList/array_list_internal.h
        ArrayList/array_list_internal.c
        ArrayList/array_list.h
        CuTest/CuTest.h
        CuTest/CuTest.c
        test/ArrayListSuite.c)
