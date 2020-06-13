#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* src = fopen("hello.txt", "r");
    FILE *dest = fopen("tmp.txt", "a+");
    char buf[1024];
    int line = 0;
    while(fgets(buf, 1024, src) != NULL) {
        printf("%d: %s", ++line, buf);
        fputs(buf, dest);

    }
    
    fclose(src);
    fclose(dest);
    return 0;
}
