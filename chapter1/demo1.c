#include <stdio.h>
#include <string.h>

void test1() {
    int c, nl;
    nl = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            nl++;
        }
    }

    printf("行数: %d\n", nl);
}

void test9() {
    int c, nl;
    nl = 0;
    char inputs[1024];
    int prev_is_blank = 0;
    int index = 0;
    while((c = getchar()) != '\n') {
        // printf("%d ", c);
        if(c == ' ' && prev_is_blank) {
            continue;
        } else if(c == ' ') {
            prev_is_blank = 1;
        } else {
            prev_is_blank = 0;
        }
        inputs[index++] = c;
    }
    inputs[index] = '\0';

    printf("len: %ld, after handler: %s\n", strlen(inputs), inputs);

}

int main(int argc, char const *argv[])
{
    test9();
    return 0;
}
