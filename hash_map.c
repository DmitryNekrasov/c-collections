#include <malloc.h>
#include <stdio.h>

#include "hash_map.h"
#include "constants.h"

#define LOAD_FACTOR 0.75
#define INITIAL_BUCKET_NUMBER 8

struct list_node {
    struct string* key;
    int value;
    struct list_node* next;
};

struct hash_map {
    int size;
    int bucket_number;
    double load_factor;
    struct list_node** buckets;
};

struct list_node* init_list_node(struct string* key, int value, struct list_node* next) {
    struct list_node* new_node = (struct list_node*) malloc(sizeof (struct list_node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

struct list_node* lookup(struct list_node* node, const struct string* str, struct list_node** prev) {
    while (node != NULL) {
        if (equals(node->key, str)) {
            return node;
        }
        if (prev != NULL) {
            *prev = node;
        }
        node = node->next;
    }
    return NULL;
}

void allocate_buckets(struct hash_map* this) {
    this->buckets = (struct list_node**) malloc(sizeof (struct list_node*) * this->bucket_number);
    for (int i = 0, ei = this->bucket_number; i < ei; i++) {
        this->buckets[i] = (struct list_node*) malloc(sizeof (struct list_node));
        this->buckets[i]->key = NULL;
        this->buckets[i]->next = NULL;
    }
}

struct hash_map* init_hash_map() {
    struct hash_map* map = (struct hash_map*) malloc(sizeof (struct hash_map));
    map->size = 0;
    map->load_factor = LOAD_FACTOR;
    map->bucket_number = INITIAL_BUCKET_NUMBER;
    allocate_buckets(map);
    return map;
}

struct list_node* head_by_key(const struct hash_map* this, const struct string* key) {
    int bucket_index = hash_code(key) & (this->bucket_number - 1);
    return this->buckets[bucket_index];
}

void put_internal(struct  hash_map* this, struct string* key, int value, int need_lookup) {
    struct list_node* head = head_by_key(this, key);
    struct list_node* node = need_lookup ? lookup(head, key, NULL) : NULL;
    if (node != NULL) {
        node->value = value;
        destroy_string(key);
    } else {
        this->size++;
        struct list_node* new_node = init_list_node(key, value, head->next);
        head->next = new_node;
    }
}

void realloc_map(struct hash_map* this) {
    struct list_node** old_buckets = this->buckets;
    int old_bucket_number = this->bucket_number;
    this->bucket_number *= 2;
    this->size = 0;
    allocate_buckets(this);
    for (int i = 0; i < old_bucket_number; i++) {
        struct list_node* node = old_buckets[i]->next;
        while (node != NULL) {
            put_internal(this, node->key, node->value, FALSE);
            struct list_node* next = node->next;
            free(node);
            node = next;
        }
        free(old_buckets[i]);
    }
    free(old_buckets);
}

void put(struct hash_map* this, const char* c_str, int value) {
    if (this->size > this->load_factor * this->bucket_number) {
        realloc_map(this);
    }
    struct string* key = init_string(c_str);
    put_internal(this, key, value, TRUE);
}

int get(const struct hash_map* this, const char* c_str) {
    struct string* key = init_string(c_str);
    struct list_node* head = head_by_key(this, key);
    struct list_node* node = lookup(head, key, NULL);
    int result = node == NULL ? INT_MIN_VALUE : node->value;
    destroy_string(key);
    return result;
}

int contains(const struct hash_map* this, const char* c_str) {
    struct string* key = init_string(c_str);
    struct list_node* head = head_by_key(this, key);
    int exist = lookup(head, key, NULL) != NULL;
    destroy_string(key);
    return exist;
}

int size(const struct hash_map* this) {
    return this->size;
}

void print_map_debug(const struct hash_map* this) {
    for (int i = 0, ei = this->bucket_number; i < ei; i++) {
        printf("[%2d]", i);
        struct list_node* node = this->buckets[i]->next;
        while (node != NULL) {
            printf(" -> (");
            print_string(node->key);
            printf(", %d)", node->value);
            node = node->next;
        }
        printf(" -> nil\n");
    }
}

void destroy_map(struct hash_map* this) {
    for (int i = 0, ei = this->bucket_number; i < ei; i++) {
        struct list_node* node = this->buckets[i]->next;
        while (node != NULL) {
            destroy_string(node->key);
            struct list_node* next = node->next;
            free(node);
            node = next;
        }
        free(this->buckets[i]);
    }
    free(this->buckets);
    free(this);
}

void get_key_values(const struct hash_map* this, char** keys, int* values) {
    int index = 0;
    for (int i = 0, ei = this->bucket_number; i < ei; i++) {
        const struct list_node* node = this->buckets[i]->next;
        while (node != NULL) {
            keys[index] = c_str(node->key);
            values[index] = node->value;
            index++;
            node = node->next;
        }
    }
}

void print_map(const struct hash_map* this) {
    int n = this->size;
    printf("{");
    if (n > 0) {
        char** keys = (char**) malloc(sizeof (char*) * n);
        int* values = (int*) malloc(sizeof (int) * n);
        get_key_values(this, keys, values);
        for (int i = 0; i < n - 1; i++) {
            printf("%s=%d, ", keys[i], values[i]);
        }
        printf("%s=%d", keys[n - 1], values[n - 1]);
        free(values);
        free(keys);
    }
    printf("}\n");
}

int remove_by_key(struct hash_map* this, const char* c_str) {
    struct string* key = init_string(c_str);
    struct list_node* head = head_by_key(this, key);
    struct list_node* prev;
    struct list_node* node = lookup(head, key, &prev);
    int find = FALSE;
    if (node != NULL) {
        find = TRUE;
        prev->next = node->next;
        destroy_string(node->key);
        free(node);
    }
    destroy_string(key);
    return find;
}