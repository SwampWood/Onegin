#include <stdio.h>
#include <TXLib.h>

const int LENGHT_OF_STRING = 80;

size_t GetWholeText(char text[][LENGHT_OF_STRING], FILE* text_file);
void PrintResult(char text[][LENGHT_OF_STRING], size_t count_of_strings);

int main() {
    FILE* onegin_file;
    onegin_file = fopen("text.txt", "r");
    char text[][LENGHT_OF_STRING] = {};
    size_t count_of_rows = GetWholeText(text, onegin_file);
    PrintResult(text, count_of_rows);
    return 0;
}

size_t GetWholeText(char text[][LENGHT_OF_STRING], FILE* text_file) {
//TODO �������� ������ ��������� ������ (������������ ��������) �� ����� ������
    size_t len = 0;
    while (fgets(text[i], LENGHT_OF_STRING, text_file) != NULL)
        ++len;
    return len;
}

void PrintResult(char text[][LENGHT_OF_STRING], size_t count_of_strings) {
    for (size_t cur_string = 0; cur_string <= count_of_strings) {
        printf("%s", text[cur_string]);
    }
}
