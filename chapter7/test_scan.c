#include <stdio.h>


int main(int argc, char const *argv[])
{
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);
    printf("%d年-%d月-%d日\n", year, month, day);
    return 0;
}
