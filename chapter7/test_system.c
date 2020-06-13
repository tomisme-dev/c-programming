#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    system("date");
    int result = system("./print");
    printf("result==%d\n", result);
    return 0;
}
