#include <stdio.h>
#include <inttypes.h>
#include <string.h>

void count_sum(void) {
    char *path = "in1.txt";
    FILE *file;
    int sum = 0, n;
    file = fopen(path, "r");
    while (fscanf(file, "%d", &n) == 1)
        sum += n;
    fclose(file);
    printf("%d\n", sum);
}

//посчитать кол-во цифр в фале и записть в конец файла
void count_digit_in_file(void) {
    char *path = "in1.txt";
    FILE *file;
    int counter = 0;
    signed char c;
    file = fopen(path, "r+"); //режим чтения и дозапись
    while ( (c = fgetc(file)) != EOF)
        if (c >= '0' && c <= '9') 
            counter++;
    fprintf(file, " %d", counter); //тут указатель стоит на конце файла и пишем туда
    printf("counter = %d\n", counter);
    fclose(file);
}

//размер файла посчитает
void get_file_size(char *path) {
    FILE *file;
    size_t size;
    file = fopen(path, "r");
    if (file != NULL) {
        fseek(file, 0, SEEK_END); //ставим указатель в конец файла
        size = ftell(file); //чтьаем позицию указатель в байтах
        fclose(file);
        if (size >= 1024)
            printf("File size of '%s' - %u KB.\n", path, size / 1024);
        else
            printf("File size of '%s' - %u B.\n", path, size);
    } else {
        printf("Can't open file %s\n", path);
    }
}

//повторяет содержимое файла
void repeat_file_content(int repeat_count) {
    enum {line_width = 256};
    char line[line_width];
    char *input = "in2.txt";
    char *output = "out2.txt";
    char c;
    FILE *file;

    if ( (file = fopen(input, "r")) == NULL) {
        perror("Error file openning");
        return;
    }

    int count = 0;
    while ( ((c = fgetc(file)) != EOF) && (c != '\n') && count < line_width)
        line[count++] = c;
    line[count] = 0;
    fclose(file);
    printf("%s", line);

    if ( (file = fopen(output, "w")) == NULL) {
        perror("Error file openning for write");
        return;
    }

    for (int i = 0; i < repeat_count; i++) {
        if (i)
            fprintf(file, ", "); //всего 2 запятых
        fprintf(file, "%s", line);
    }
    fprintf(file, " %d", count);
    fclose(file);
}

void read_csv(void) { 
    enum {CARRIAGE_RETURN = 0xD};
    int counter = 0;
    int param_qty = 3;
    int arr[3] = {0};
    char ch;
    char *input_csv = "input.csv";
    FILE *csv_file = fopen(input_csv, "r");

    while ( (ch = fgetc(csv_file)) != EOF)
    {   

        if (ch == ';') {
            counter++;
            if (counter > param_qty) 
                counter = 0;
        }
        else if (ch == '\n') {
            if (counter == param_qty - 1)
                printf("%d = %d;%d;%d\n", counter, arr[0], arr[1], arr[2]);
            else 
                printf("ERROR %d = %d;%d;%d\n", counter, arr[0], arr[1], arr[2]);
            counter = 0;
            arr[0] = arr[1] = arr[2] = 0;
        }
        else if (ch >= '0' && ch <= '9') 
            arr[counter] = arr[counter] * 10 + ch - '0';
        else if (ch != CARRIAGE_RETURN)
            counter = 0;
    }
}

void read_write_bin_file(void) {
    uint32_t i = 0x31323334, u = 0;
    FILE *file_bin = fopen("out.bin", "wb");
    fwrite(&i, sizeof(int), 1, file_bin);
    fclose(file_bin);
    file_bin = fopen("out.bin", "rb");
    fread(&u, 2, 1, file_bin);
    fclose(file_bin);
    printf("u = %x\n", u);
}

void struct_exp(void) {
    typedef struct student
    {
        char name[50];
        uint32_t group;
        char country[50];
    } student; 
    student student1 = {.name = "Ivan", .group = 768, .country = "Russia"};
    student student2;

    struct student* pst = &student1;
    student2 = student1;
    pst -> group = 101; //так предпочтительнее
    strcpy(student1.name, "Alexey");
    printf("group = %d\n", student1.group);
    printf("name = %s\n", student1.name);
    (*pst).group = 102;
    printf("group = %d\n", student1.group);
    printf("group = %d\n", student2.group);
}



int main(int argc, char const *argv[])
{
    // count_sum();
    // count_digit_in_file();
    // get_file_size("in1.txt");
    // repeat_file_content(20);
    // get_file_size("out2.txt");
    // read_csv();
    // read_write_bin_file();
    struct_exp();
    return 0;
}
