#ifndef HASH_MAP_HASH_MAP_H
#define HASH_MAP_HASH_MAP_H

#include "string.h"

struct hash_map;

struct hash_map* init_hash_map();
void put(struct hash_map* this, const char* key, int value);
int get(const struct hash_map* this, const char* key);
int contains(const struct hash_map* this, const char* key);
int size(const struct hash_map* this);
void print_map_debug(const struct hash_map* this);
void destroy_map(struct hash_map* this);
void get_key_values(const struct hash_map* this, char** keys, int* values);
void print_map(const struct hash_map* this);

#endif //HASH_MAP_HASH_MAP_H
