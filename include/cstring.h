//
// Created by mawe on 7/23/25.
//

#ifndef CSTRING_H
#define CSTRING_H
#include <stddef.h>

typedef struct {
    char* buffer;
    size_t size;
} cstring_t;

cstring_t* cstring_create(const char* str);
void cstring_destroy(cstring_t* cstring);
cstring_t* cstring_copy(const cstring_t* cstring);
cstring_t* cstring_append(cstring_t* cstring, const cstring_t* cstring2);

#endif //CSTRING_H
