//
// Created by mawe on 7/23/25.
//

#include "cstring.h"

#include <stdlib.h>
#include <string.h>

cstring_t* cstring_create(const char* str) {
    const size_t len = strlen(str);
    cstring_t* cstring = malloc(sizeof(cstring_t));
    cstring->buffer = malloc(len + 1);
    memcpy(cstring->buffer, str, len);
    cstring->size = strlen(str) + 1;

    if (cstring->buffer[len] != '\0') {
        cstring->buffer[len] = '\0';
    }

    return cstring;
}

void cstring_destroy(cstring_t* cstring) {
    if (cstring == NULL) {
        return;
    }
    if (cstring->buffer != NULL) {
        free(cstring->buffer);
    }
    cstring->buffer = NULL;
    cstring->size = 0;
}

cstring_t* cstring_copy(const cstring_t* cstring) {
    cstring_t* cstring2 = malloc(sizeof(cstring_t));
    cstring2->buffer = malloc(cstring->size);
    memcpy(cstring2->buffer, cstring->buffer, cstring->size);
    cstring2->size = cstring->size;
    return cstring2;
}

cstring_t* cstring_append(cstring_t* cstring, const cstring_t* cstring2) {
    char* tmp = realloc(cstring->buffer, cstring->size + cstring2->size);
    if (tmp == NULL) {
        return NULL;
    }
    cstring->buffer = tmp;
    memcpy(cstring->buffer + cstring->size, cstring2->buffer, cstring2->size);
    cstring->size += cstring2->size;
    return cstring;
}