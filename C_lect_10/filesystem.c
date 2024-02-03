#include "filesystem.h"

void convert_path_to_full(char *full_path, const char *dir)
{
    if (dir[0] == '/')
    {
        strcpy(full_path, dir);
    }
    else if (dir[0] == '.')
    {
        getcwd(full_path, PATH_LENGTH);
    }
    else
    {
        getcwd(full_path, PATH_LENGTH);
        strcat(full_path, "/");
        strcat(full_path, dir);
    }
    if (full_path[strlen(full_path) - 1] != '/')
        strcat(full_path, "/"); // добавляем / в конце
}

/*
void print_filetype(int type)
{
    switch (type)
    {
    case DT_BLK:
        printf("b ");
        break;
    case DT_CHR:
        printf("c ");
        break;
    case DT_DIR:
        printf("d ");
        break; // directory
    case DT_FIFO:
        printf("p ");
        break; // fifo
    case DT_LNK:
        printf("l ");
        break; // Sym link
    case DT_SOCK:
        printf("s ");
        break; // Filetype isn't
        identified default : printf(" ");
        break;
    }
}
*/

/**
Расширить строку пробелами.
@print_lenth длина до которой надо расширить
*/
void print_space(int print_lenth, int str_lenth)
{
    while ((print_lenth - str_lenth) > 0)
    {
        putchar(' ');
        str_lenth++;
    }
}

void print_tab(int tab_number)
{
    for (int t = 1; t < tab_number; t++)
    {
        putchar('\t');
    }
}

void print_file_size(long long int byte_number)
{
    if (byte_number / (1024 * 1024))
        printf("%lld Mb", byte_number / (1024 * 1024));
    else if (byte_number / 1024)
        printf("%lld Kb", byte_number / 1024);
    else
        printf("%lld b", byte_number);
}

void ls(const char *dir)
{
    static int tab_count = 0; //уровень вложенности рекурсии
    tab_count++;
    struct stat file_stats;
    DIR *folder;
    struct dirent *entry;
    int files_number = 0;
    char full_path[PATH_LENGTH] = {0};
    convert_path_to_full(full_path, dir);
    folder = opendir(full_path);

    if (folder == NULL)
    {
        perror("Unable to read directory ");
        printf("%s\n", full_path);
        return;
    }

    while ((entry = readdir(folder)))
    {
        if (entry->d_name[0] == '.') // пропускаем поддиректории
            continue;
        char full_filename[PATH_LENGTH] = {0};
        files_number++;
        print_tab(tab_count); //отступы при рекурсии
        printf("%4d : ", files_number);
        // print_filetype(entry->d_type);
        strcpy(full_filename, full_path);
        strcat(full_filename, entry->d_name);
        printf("%s", entry->d_name);
        print_space(20, entry->d_namlen);
        if (!stat(full_filename, &file_stats))
        {
            print_file_size(file_stats.st_size);
            printf("\n");
        }
        else
        {
            printf("stat failed for this file\n");
            perror(0);
        }
    }
    closedir(folder);
    tab_count--;
}