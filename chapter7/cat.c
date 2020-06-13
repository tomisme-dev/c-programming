#include <stdio.h>

void copyfile(FILE *src, FILE *dest) {
    int c;
    while((c = getc(src)) != EOF) {
        putc(c, dest);
    }
}


/**
 * 将多个文件合并输出到控制台
 * 
*/
int main(int argc, char const *argv[])
{
    if(argc == 1) {
        // 将stdin输出到控制台
        copyfile(stdin, stdout);
    } else {
        for(int i = 0; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            copyfile(file, stdout);
            fclose(file);
        }
    }
    return 0;
}


