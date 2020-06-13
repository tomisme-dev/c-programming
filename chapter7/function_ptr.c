#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef void (*func)(void);

void f()
{
    printf("function f....\n");
}

void f2()
{
    printf("function f2....\n");
}

void f3()
{
    putchar(toupper('a'));
}

void f4()
{
    int a = 12;
    int *p = &a;
    long x = (long)p;
    printf("%p, %ld", p, x);
}

void test(func p)
{
    p();
}

int main(int argc, char *argv[])
{
    func p;
    if (argc == 2)
    {
        char *func = argv[1];
        if (strcmp(func, "f") == 0)
        {
            p = f;
        }
        else if ((strcmp(func, "f3") == 0))
        {
            p = f3;
        }
        else if ((strcmp(func, "f4") == 0))
        {
            p = f4;
        }
        else
        {
            p = f2;
        }
        test(p);
    }
    else
    {
        printf("error args\n");
    }
    return 0;
}
