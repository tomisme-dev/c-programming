#include <stdarg.h>
#include <stdio.h>

int sum(int arg_num, ...) {
    int total = 0;
    va_list ap; /* points to each unnamed arg in turn */
    va_start(ap, arg_num); /* make ap point to 1st unnamed arg */

    int ival = 0;
    for(int i = 0; i < arg_num; i++) {
        int ival = va_arg(ap, int); // 运行完后，指向下一个参数
        total += ival;
    }

    va_end(ap); /* clean up when done */
    return total;
}


int main(int argc, char const *argv[])
{
    printf("sum=%d\n", sum(4, 1,2,3,4));
    return 0;
}


