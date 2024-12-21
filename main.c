#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main (int argc, char *argv[]) {
    const char *morse = "-.. .- ...- .. -.. .  ..--- -----";
    char **morse_words = morse_phrase_to_morse_word_list(morse);
    char **words = morse_word_list_to_word_list(morse_words);
    char *phrase = word_list_to_phrase(words);

    printf("%s\n", phrase);

    // Libération de la mémoire
    free_word_list(morse_words);
    free_word_list(words);
    free(phrase);

    return 0;
}