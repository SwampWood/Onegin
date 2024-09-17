#ifndef FILE_READ_H_INCLUDED
#define FILE_READ_H_INCLUDED
enum RESPONSE_CODES_FOR_READFILE {
    SUCCESSFUL_READ = 0,
    FAIL_READ = 1,
};

enum RESPONSE_CODES_FOR_READFILE ReadTextFromFile(struct Text* full_text, const char* name_of_file);

#endif // FILE_READ_H_INCLUDED
