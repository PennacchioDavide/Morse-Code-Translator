#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

// To copy a string
char *strdup_safe(const char *s) {
    char *copy = malloc(strlen(s) + 1);
    if (copy) strcpy(copy, s);
    return copy;
}

char **morse_phrase_to_morse_word_list(const char *phrase) {
    char **word_list = malloc(100 * sizeof(char *));
    int j = 0;
    char buffer[100];
    int k = 0;

    for (int i = 0; phrase[i] != '\0'; i++) {
        if (phrase[i] == ' ' && phrase[i+1] == ' ') { 
            buffer[k] = '\0';
            word_list[j++] = strdup_safe(buffer);
            k = 0;
            i++;
        } else {
            buffer[k++] = phrase[i];
        }
    }

    
    if (k > 0) {
        buffer[k] = '\0';
        word_list[j++] = strdup_safe(buffer);
    }
    word_list[j] = NULL; 
    return word_list;
}

char **morse_word_list_to_word_list(char **morse_word_list) {
    char **word_list = malloc(100 * sizeof(char *));
    int i = 0;

    while (morse_word_list[i] != NULL) {
        word_list[i] = morse_word_to_word(morse_word_list[i]);
        i++;
    }
    word_list[i] = NULL; 
    return word_list;
}

char *morse_word_to_word(const char *morse_word) {
    char word[100] = "";
    char buffer[10];
    int k = 0;

    for (int i = 0; morse_word[i] != '\0'; i++) {
        if (morse_word[i] == ' ') {
            buffer[k] = '\0';
            strncat(word, (char[]){morse_letter_to_letter(buffer), '\0'}, 1);
            k = 0;
        } else {
            buffer[k++] = morse_word[i];
        }
    }

    if (k > 0) {
        buffer[k] = '\0';
        strncat(word, (char[]){morse_letter_to_letter(buffer), '\0'}, 1);
    }

    return strdup_safe(word);
}

char morse_letter_to_letter(const char *morse) {
    for (int i = 0; i < morse_map_size; i++) {
        if (strcmp(morse, morse_map[i].morse) == 0) {
            return morse_map[i].letter;
        }
    }
    return '?';
}

char *word_list_to_phrase(char **word_list) {
    char phrase[1000] = "";

    for (int i = 0; word_list[i] != NULL; i++) {
        strcat(phrase, word_list[i]);
        if (word_list[i + 1] != NULL) strcat(phrase, " ");
    }

    return strdup_safe(phrase);
}

void free_word_list(char **word_list) {
    for (int i = 0; word_list[i] != NULL; i++) {
        free(word_list[i]);
    }
    free(word_list);
}