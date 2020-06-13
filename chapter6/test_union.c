#include <stdio.h>


union u
{
    int x;
    char y;
};


int main(int argc, char const *argv[])
{
    union u u1;
    // u1.x = 0x12345678;
    u1.y = 0x12;
    printf("u.y: %x\n", u1.y);
    return 0;
}

