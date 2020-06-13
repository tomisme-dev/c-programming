#include <stdio.h>

#define MAXC 1024

int main(int argc, char const *argv[])
{
    int c;
    char cs[MAXC];
    int start = 0;
    while((c = getchar()) != EOF) {
        cs[start++] = c;
    }

    cs[start] = '\0';

    printf("output: %s", cs);
    return 0;
}
