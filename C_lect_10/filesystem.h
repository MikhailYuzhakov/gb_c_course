#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

enum
{
    PATH_LENGTH = 256
};

#define STR255 "%255s"

void convert_path_to_full(char*, const char*);
void print_filetype(int);
void print_space(int, int);
void print_tab(int);
void print_file_size(long long int);
void ls(const char*);