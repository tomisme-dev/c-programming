#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int count;
    char buf[1024];
    while ((count = read(0, buf, 1024)) > 0)
    {
        printf("len=%ld, count=%d\n", strlen(buf), count);
        write(1, buf, count);
    }
    
    return 0;
}
