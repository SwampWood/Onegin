#include <stdio.h>
#include <TXLib.h>

const int LENGHT_OF_STRING = 80;
const char* const FILENAME = "text.txt";

size_t GetWholeText(char text[][LENGHT_OF_STRING], FILE* text_file);
void PrintResult(char text[][LENGHT_OF_STRING], size_t count_of_strings);

int main() {
    FILE* onegin_file;
    assert(FILENAME != NULL);
    onegin_file = fopen(FILENAME, "r");
    char text[][LENGHT_OF_STRING] = {};
    size_t count_of_rows = GetWholeText(text, onegin_file);
    printf("%s", text[0]);
    PrintResult(text, count_of_rows);
    return 0;
}

size_t GetWholeText(char text[][LENGHT_OF_STRING], FILE* text_file) {
    //TODO поменять индекс последней строки (возвращаемое значение) на длину текста
    size_t len = 0;
    while (fgets(text[len], LENGHT_OF_STRING, text_file) != NULL) {
        assert(text[len] != NULL);
        ++len;
    }
    return len;
}

void PrintResult(char text[][LENGHT_OF_STRING], size_t count_of_strings) {
    for (size_t cur_string = 0; cur_string <= count_of_strings; cur_string++) {
        printf("%s", text[cur_string]);
    }
}
