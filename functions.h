#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dictionary.h"

char **morse_phrase_to_morse_word_list(const char *phrase);
char **morse_word_list_to_word_list(char **morse_word_list);
char *morse_word_to_word(const char *morse_word);
char morse_letter_to_letter(const char *morse);
char *word_list_to_phrase(char **word_list);
void free_word_list(char **word_list);

#endif