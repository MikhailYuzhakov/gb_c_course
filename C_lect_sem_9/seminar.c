#include <stdio.h>
#include <inttypes.h>

void count_last_symbol(char *filepath) {
    char last_symbol;
    char cur_symbol;
    FILE *f_in;
    f_in = fopen(filepath, "r");
    fseek(f_in, -1, SEEK_END);
    last_symbol = fgetc(f_in);
    printf("last_symbol = %c\n", last_symbol);
    fseek(f_in, 0, SEEK_SET);
    while ( (cur_symbol = fgetc(f_in)) != EOF)
    {
        if (cur_symbol == last_symbol)
            printf("%d ", ftell(f_in) - 1);
    }
    
    fclose(f_in);
}

void count_case_letters(char *input, char *output) {
    char symbol;
    uint8_t small = 0;
    uint8_t big = 0;
    FILE *f_in, *f_out;
    f_in = fopen(input, "r");
    fseek(f_in, 0, SEEK_SET);
    while ((symbol = fgetc(f_in) != EOF))
    {
        if (symbol >= 'A' && symbol <= 'Z') big++;
        if (symbol >= 'a' && symbol <= 'z') small++;
        printf("%c ", symbol);
    }
    fclose(f_in);
    f_out = fopen(output, "w");
    fprintf(f_out, "%d %d", small, big);
    fclose(f_out);
}

int main(int argc, char const *argv[])
{
    // count_last_symbol("input.txt");
    count_case_letters("in.txt", "out.txt");
    return 0;
}
