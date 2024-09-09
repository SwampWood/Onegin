#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "get_text.h"

void GetWholeText(char text[][LENGHT_OF_STRING], size_t count_of_rows) {
    FILE* text_file = fopen(FILE_NAME, "r");
    size_t current_line = 0;

    while (current_line < count_of_rows) {
        fgets(text[current_line], LENGHT_OF_STRING, text_file);
        ++current_line;
    }
}

size_t GetSizeText(void) {
    size_t count_lines = 0;
    char buffer[LENGHT_OF_STRING] = {};
    FILE* text_file = fopen(FILE_NAME, "r");

    while (fgets(buffer, LENGHT_OF_STRING, text_file) != NULL) {
        ++count_lines;
    }
    return count_lines;
}
