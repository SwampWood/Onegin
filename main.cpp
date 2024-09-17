#include <stdio.h>
#include <stdlib.h>
#include <TXLib.h>
#include "file_read.h"
#include "text_struct.h"

typedef int (*CompareFuncT) (const void* a, const void* b);

void SwitchPointers(void* pointer1, void* pointer2);
int CompareStrings(const void* string_target, const void* string_base);
void BubbleSort(void* data, size_t elem_size, size_t count_of_elems, CompareFuncT CompareFunc);
void PrintText(struct Text* full_text);
void ClearMemory(struct Text* full_text);

int main() {
    struct Text onegin = {NULL, 0, NULL};
    char name[] = "verse1.txt";
    ReadTextFromFile(&onegin, name);
    printf("%d\n", onegin.text_lenght);
    BubbleSort(onegin.pointers_to_lines, sizeof(char*), onegin.text_lenght, CompareStrings);
    PrintText(&onegin);
    ClearMemory(&onegin);
    return 0;
}

void SwitchPointers(void** pointer1, void** pointer2) {
    void* pointer_tmp = *pointer1;
    *pointer1 = *pointer2, *pointer2 = pointer_tmp;
}

int CompareStrings(const void* string_target, const void* string_base) {
    int i = 0;
    const char* real_target = *(const char* *) string_target;
    const char* real_base = *(const char* *) string_base;
    while (real_base[i] != '\0' && real_base[i] == real_target[i]) {
        i++;
    }
    return real_target[i] - real_base[i];
}

void BubbleSort(void* data, size_t elem_size, size_t count_of_elems, CompareFuncT CompareFunc) {
    for (size_t i = 0; i < count_of_elems - 1; ++i) {
        for (size_t j = 0; j < count_of_elems - 1 - i; ++j) {
            if (CompareFunc(data + j * elem_size, data + (j + 1) * elem_size) > 0) {
                SwitchPointers(&(data + j * elem_size), &(data + (j + 1) * elem_size));
            }
        }
    }
}

void PrintText(struct Text* full_text) {
    for (size_t i = 0; i < full_text->text_lenght; i++) {
        printf("%s", full_text->pointers_to_lines[i]);
    }
}

void ClearMemory(struct Text* full_text) {
    // Освобождаем выделенную память
    for (int i = 0; i < full_text->text_lenght; i++) {
        free(full_text->pointers_to_lines[i]);
    }
    free(full_text->pointers_to_lines);
}
