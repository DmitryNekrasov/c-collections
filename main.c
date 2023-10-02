#include <stdio.h>
#include <string.h>

#include "hash_map.h"

#define MAX_STR_NUMBER 500
#define MAX_LEN 2000
#define DELIMITERS " .,!?:;\n"

char text[MAX_STR_NUMBER][MAX_LEN];

void to_lower_case(char* s) {
    static const int diff = 'a' - 'A';
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += diff;
        }
        i++;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        const char* path = argv[1];
        FILE* file = fopen(path, "r");
        if (file != NULL) {
            int index = 0;
            int token_count = 0;
            struct hash_map* map = init_hash_map();
            while (fgets(text[index], MAX_LEN, file)) {
                char* str = text[index];
                char* token = strtok(str, DELIMITERS);
                while (token) {
                    to_lower_case(token);
                    int count = contains(map, token) ? get(map, token) : 0;
                    put(map, token, count + 1);
                    token = strtok(NULL, DELIMITERS);
                    token_count++;
                }
                index++;
            }
            print_map_debug(map);
            print_map(map);
            printf("size = %d\n", size(map));
            printf("token_count = %d\n", token_count);
            destroy_map(map);
            fclose(file);
        }
    }
    return 0;
}
