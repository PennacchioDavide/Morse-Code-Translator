#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stddef.h>

typedef struct {
    char *morse;
    char letter;
} MorseCode;

extern MorseCode morse_map[]; 

extern const size_t morse_map_size;

#endif