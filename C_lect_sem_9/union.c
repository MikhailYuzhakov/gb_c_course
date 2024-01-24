#include <stdio.h>
#include <stdint.h>
#include <string.h>

//хранит разные типы данных по одному адресу
//и позволяет обращаться к ним так же
union intbytes
{
    uint32_t number;
    uint8_t bytes[4];
} d;

//хранит константы 
enum operation {
    ADD = 1,
    MLT = 2,
    SUB = 3
};

//битовая структура позволяет хранить биты
//например дисплей разрешением 5х3
struct point
{
    uint8_t x:5; //занимает биты с 0 по 5, числа 0-31
    uint8_t y:3; //занимает биты с 6 по 8, числа 0-7
};

void test_bit_struct(void) {
    struct point center = {0, 5};
    center.x = 2;
    printf("x = %d, y = %d\n", center.x, center.y);
}

void test_union(void) {
    d.number = 0x12345678;
    printf("Number %x = ", d.number);
    printf("in memory id %x %x %x %x", d.bytes[0], d.bytes[1], d.bytes[2], d.bytes[3]);
}

int calculation(int x, int y, enum operation op) {
    switch (op)
    {
    case ADD:
        return x + y;
    case SUB:
        return x - y;
    case MLT:
        return x * y;
    default:
        return 0;
    }
}

void test_enum(void) {
    enum operation op = ADD;
    int res = calculation(5, 6, op);
    printf("result = %d\n", res);
}

int main(int argc, char const *argv[])
{
    // test_union();
    // test_enum();
    test_bit_struct();
    return 0;
}
