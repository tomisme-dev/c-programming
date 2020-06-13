#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[1024];
    sprintf(buf, "hello, %s", "world");
    sprintf(buf+strlen(buf), "good night.");
    printf("output: %s\n", buf);
    return -1;
}
