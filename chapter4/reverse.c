#include <string.h>
#include <stdio.h>

void reverse(char *s, int n) {
    if(n <= 1) {
        return;
    }

    char tmp = *s;
    *s = *(s+n-1);
    *(s+n-1) = tmp;

    reverse(s+1, n - 2);
    
    return;
}


int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("usage: %s <str>\n", argv[0]);
        return -1;
    }
    reverse(argv[1], strlen(argv[1]));

    printf("reverse: %s\n", argv[1]);


    return 0;
}