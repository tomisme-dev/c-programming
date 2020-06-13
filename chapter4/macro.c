#include <stdio.h>

#define MAX(A, B) ((A>B) ? (A): (B))



int main(int argc, char const *argv[])
{
    /* code */
    double m = MAX(1, 2.3);
    printf("max=%f\n", m);
    return 0;
}


#undef MAX


void f() {
    // MAX(1,2);


    char * s = "ab" "cd";
}