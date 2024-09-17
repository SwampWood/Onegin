#ifndef TEXT_STRUCT_H_INCLUDED
#define TEXT_STRUCT_H_INCLUDED

struct Text {
    char** pointers_to_lines;
    size_t text_lenght;
    char* name_of_file;
};

#endif // TEXT_STRUCT_H_INCLUDED
