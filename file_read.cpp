#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <TXLib.h>
#include "file_read.h"
#include "text_struct.h"

void ReadTextFromFile(struct Text* full_text, char* name_of_file) {
    full_text->name_of_file = name_of_file;

    struct stat *buf;

    buf = (struct stat*) calloc(1, sizeof(struct stat));
    stat(name_of_file, buf);
    full_text->buffer_lenght = buf->st_size;
    printf("%d", full_text->buffer_lenght);

    full_text->buffer = (char*) calloc(full_text->buffer_lenght, 1);
}
