#include <stdio.h>

#include "hash_map.h"

int main() {
    struct hash_map* map = init_hash_map();

    put(map, "hello", 8);
    put(map, "bgfdb", 4);
    put(map, "vthv", 3);
    put(map, "fgf", 10);
    put(map, "fghfg", 101);
    put(map, "vgvsd", 56);
    put(map, "hfgjfhj", 123);
    put(map, "sgjdhjhf", 21);
    put(map, "test", 1);
    put(map, "test", 2);
    put(map, "test", 3);
    put(map, "test", 4);
    put(map, "test", 5);
    put(map, "helslo", 8);
    put(map, "bgfsdb", 4);
    put(map, "vtdfhv", 3);
    put(map, "fgdfqrgf", 10);
    put(map, "fghfqg", 101);
    put(map, "vgvqsd", 56);
    put(map, "hfgjqfhj", 123);
    put(map, "sgjdsdhjhf", 21);
    put(map, "testgb", 1);
    put(map, "tesnmt", 2);
    put(map, "tesnjt", 3);
    put(map, "tesdsdsdt", 4);
    put(map, "tesbbbt", 5);

    printf("size = %d\n", size(map));

    printf("contains = %d\n", contains(map, "hello"));
    printf("contains = %d\n", contains(map, "hello!"));
    printf("contains = %d\n", contains(map, "hfgjfhjdfgn!"));
    printf("contains = %d\n", contains(map, "sdfdsc"));
    printf("contains = %d\n", contains(map, "test"));
    printf("contains = %d\n", contains(map, "sssasas"));
    printf("contains = %d\n", contains(map, "qwwww"));

    printf("get = %d\n\n", get(map, "fghfg"));

    print_map_debug(map);
    print_map(map);

    destroy_map(map);

    return 0;
}
