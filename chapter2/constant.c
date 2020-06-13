#include <stdio.h>

enum bool {NO, YES};

int main(int argc, char const *argv[])
{
    const int a = 10;
    const int arr[12];
    const int arr2[] = {1, 3, 4};
    enum bool b = YES;
    // a = 12; // error
    // arr[0] = 9;
    printf("arr2[0]=%d\n", arr2[0]);
    printf("bool=%d", b);
    return 0;
}
