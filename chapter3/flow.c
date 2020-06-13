#include <stdio.h>

int strindex(char s[], char t[]);

void test_ungetc() {
    int in = '1';
    ungetc('x', stdin);
    int in2 = getchar();

    printf("in1=%c, in2=%c\n", in, in2);
}

int main(int argc, char const *argv[])
{
    char *s = "hello world";
    char *t = "llow";
    printf("index:%d\n", strindex(s, t));
    test_ungetc();
    return 0;
}


int strindex(char s[], char t[]) {
    for(int i = 0; s[i] != '\0'; i++) {
        int j = 0;
        for(; s[i] != '\0' && t[j] != '\0' && s[i] == t[j]; j++, i++) {

        }

        if(t[j] == '\0') {
            return i - j;
        }
    }

    return -1;
}