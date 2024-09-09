#include <stdio.h>
#include <TXLib.h>

const int LENGHT_OF_STRING = 60;
const char* FILE_NAME = "verse1.txt";

void GetWholeText(char text[][LENGHT_OF_STRING], size_t count_of_rows);
size_t GetSizeText(void);
void PrintResult(char text[][LENGHT_OF_STRING], size_t count_of_strings);
void SwitchStrings(char* string_first, char* string_second);
int CompareStrings(char* string_target, char* string_base);
int ReplaceString(char* string_target, const char* string_base);
void BubbleSort(char text[][LENGHT_OF_STRING], size_t count_of_strings);

int main() {
    size_t count_of_rows = GetSizeText();
    char text[count_of_rows][LENGHT_OF_STRING];
    GetWholeText(text, count_of_rows);
    BubbleSort(text, count_of_rows);
    PrintResult(text, count_of_rows);
    return 0;
}

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

void PrintResult(char text[][LENGHT_OF_STRING], size_t count_of_strings) {
    for (size_t cur_string = 0; cur_string < count_of_strings; cur_string++) {
        printf("%s", text[cur_string]);
    }
}

void SwitchStrings(char* string_first, char* string_second) {
    char string_temporary[LENGHT_OF_STRING];
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

void BubbleSort(char text[][LENGHT_OF_STRING], size_t count_of_strings) {
    for (size_t i = 0; i < count_of_strings - 1; ++i) {
        for (size_t j = 0; j < count_of_strings - 1 - i; ++j) {
            if (CompareStrings(text[j], text[j + 1]) > 0) {
                SwitchStrings(text[j], text[j + 1]);
            }
        }
    }
}
