#include <stdio.h>
#include <TXLib.h>

const int LENGHT_OF_STRING = 80;

void GetWholeText(char text[][LENGHT_OF_STRING], FILE* text_file);

int main() {
    FILE* onegin_file;
    onegin_file = fopen("text.txt", "r");
    char text[][LENGHT_OF_STRING] = {};
    GetWholeText(text, onegin_file);
    return 0;
}

void GetWholeText(char text[][LENGHT_OF_STRING], FILE* text_file) {
    int i = 0;
    while (fgets(text[i], LENGHT_OF_STRING, text_file) != NULL)
        ++i;
}
