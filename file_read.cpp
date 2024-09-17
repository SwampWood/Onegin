#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <TXLib.h>
#include "file_read.h"
#include "text_struct.h"

const int DEBUG_PRINTFS = 1;
const int MAX_LINES = 100;
const int MAX_LINE_LEN = 256;

enum RESPONSE_CODES_FOR_READFILE ReadTextFromFile(struct Text* full_text, const char* name_of_file) {
    assert(full_text != NULL);
    assert(full_text->text_lenght == 0);

    FILE *file = fopen(name_of_file, "r");
    if (file == NULL) {
        perror("Не удалось открыть файл");
        return FAIL_READ;
    }

    full_text->pointers_to_lines = (char** ) calloc(MAX_LINES, sizeof(char* ));

    if (full_text->pointers_to_lines == NULL) {
        perror("Ошибка выделения памяти");
        fclose(file);
        return FAIL_READ;
    }

    char buffer[MAX_LINE_LEN];
    full_text->text_lenght = 0;

    while (fgets(buffer, MAX_LINE_LEN, file) != NULL) {
        if (full_text->text_lenght >= MAX_LINES) {
            printf("Превышено максимальное количество строк\n");
            break;
        }

        // Выделяем память под строку и копируем её из буфера
        if (DEBUG_PRINTFS) {
            printf("%d\n", strlen(buffer));
        }
        full_text->pointers_to_lines[full_text->text_lenght] = (char* ) calloc((strlen(buffer) + 1), sizeof(char));
        if (full_text->pointers_to_lines[full_text->text_lenght] == NULL) {
            perror("Ошибка выделения памяти для строки");
            break;
        }
        strcpy(full_text->pointers_to_lines[full_text->text_lenght], buffer);
        full_text->text_lenght++;
    }
    if (DEBUG_PRINTFS) {
        printf("------------------\n");
    }
    fclose(file);

    // Выводим строки
    if (DEBUG_PRINTFS) {
        for (int i = 0; i < full_text->text_lenght; i++) {
            printf("%d\n", full_text->pointers_to_lines[i]);
        }
    }

    return SUCCESSFUL_READ;
}
