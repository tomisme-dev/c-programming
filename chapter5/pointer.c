#include <stdio.h>
#include <string.h>

void f1(char a[]) {
    a++;
    printf("%d\n", *(a));
}

int getNameLen(char *p);

struct Person
{
    char *name;
    int (*PgetNameLen)(char *);
};

int getNameLen(char *p) {
    return strlen(p);
}


void f2(int x) {
    char cs[x];
    cs[0] = 'a';
    cs[1] = '\0';
    printf("%s\n", cs);
}

int main(int argc, char const *argv[])
{
    // int x[] = {1, 2, 3, 4};

    // printf("x[1]=%d, *(x+1)=%d\n", x[1], *(x+1));

    char *s1 = "hello";
    char s2[] = "world";
    // *(s+1) = 'g';
    printf("%s\n", s1);
    printf("%s\n", s2);

    f1(s1);
    f1(s2);

    f2(12);
    return 0;
}
