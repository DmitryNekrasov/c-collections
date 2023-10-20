#ifndef C_COLLECTIONS_STRING_H
#define C_COLLECTIONS_STRING_H

struct string;

struct string* init_string(const char* c_str);
void destroy_string(struct string* str);
int equals(const struct string* str1, const struct string* str2);
void print_string(const struct string* this);
int length(const struct string* this);
int hash_code(const struct string* this);
const char* c_str(const struct string* this);

#endif //C_COLLECTIONS_STRING_H
