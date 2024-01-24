#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define STR_SIZE 30
#define STUDENT_NUMBER 200

typedef struct student
{
    char firstname[STR_SIZE];
    char lastname[STR_SIZE];
    uint8_t age;
} student;

void add_student(student* course, int number, char* firstname, char* lastname, uint8_t age) {
    course[number].age = age;
    strcpy(course[number].firstname, firstname);
    strcpy(course[number].lastname, lastname);
}

int get_eldest(student *course, int number) {
    int max = course -> age;
    for (int i = 1; i < number; i++)
        if (max < (course + i) -> age)  //используется указатель на следующую структуру
            max = (course + i) -> age;
    return max; 
}

int add_course(struct student* course) {
    int c = 0;
    add_student(course, c++, "Ivanov", "Ivan", 18);
    add_student(course, c++, "Sergeev", "Alexey", 19);
    add_student(course, c++, "Kazakov", "Alexey", 29);
    add_student(course, c++, "Andreev", "Timofey", 21);
    return c;
}

void print_course(student *course, int number) {
    for (int i = 0; i < number; i++)
    {
        printf("%s\t%s\t%d\n",
            course[i].firstname,
            course[i].lastname,
            course[i].age);
    }
}

int get_count_same_name(student *course, int number, char *lastname) {
    int counter = 0;
    for (int i = 0; i < number; i++)
        if (!strcmp(course[i].lastname, lastname))
            counter++;
    return counter;
}

int save_file_course(student *course, int number, char *name) {
    FILE *f = fopen(name, "wb");
    int r = 0;
    if (f) 
        r = fwrite(course, sizeof(student), number, f);
    fclose(f);
    return r;
}

int read_file_course(student *course, int number, char *name) {
    FILE *f = fopen(name, "rb");
    int r = 0;
    if (f) 
        r = fread(course, sizeof(student), number, f);
    fclose(f);
    return r;
}

int main(int argc, char const *argv[])
{
    student course[STUDENT_NUMBER];
    student course1[STUDENT_NUMBER];
    int number = add_course(course);
    print_course(course, 3);
    printf("Eldest student = %d\n", get_eldest(course, number));
    printf("Same name students qty = %d\n", get_count_same_name(course, number, "Ivan"));
    printf("bytes write = %d\n", save_file_course(course, number, "course.bin"));
    printf("bytes read = %d\n", read_file_course(course1, number, "course.bin"));
    print_course(course1, 3);
    return 0;
}
