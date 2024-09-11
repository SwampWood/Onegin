#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "file_read.h"
#include "text_struct.h"

void SwitchStrings(char* string_first, char* string_second);
int CompareStrings(char* string_target, char* string_base);
int ReplaceString(char* string_target, const char* string_base);
void BubbleSort(char** text, size_t count_of_strings);

int main() {
    struct Text onegin = {NULL, 0, NULL, 0, NULL};
    char* name = "verse1.txt";
    ReadTextFromFile(&onegin, name);
    return 0;
}

void SwitchStrings(char* string_first, char* string_second) {
    char* string_temporary;
    ReplaceString(string_temporary, string_first);
    ReplaceString(string_first, string_second);
    ReplaceString(string_second, string_temporary);
}

int CompareStrings(char* string_target, char* string_base) {
    int i = 0;
    while (string_base[i] != '\0' && string_base[i] == string_target[i]) {
        i++;
    }
    return string_target[i] - string_base[i];
}

int ReplaceString(char* string_target, const char* string_base) {
    int i = 0;
    do {
        string_target[i] = string_base[i];
        i++;
    } while (string_base[i] != '\n' && string_base[i] != '\0');
    string_target[i++] = '\n';
    string_target[i] = '\0';
    return i;
}

void BubbleSort(char** text, size_t count_of_strings) {
    for (size_t i = 0; i < count_of_strings - 1; ++i) {
        for (size_t j = 0; j < count_of_strings - 1 - i; ++j) {
            if (CompareStrings(text[j], text[j + 1]) > 0) {
                SwitchStrings(text[j], text[j + 1]);
            }
        }
    }
}
