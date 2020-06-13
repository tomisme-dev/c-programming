#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

unsigned int current_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}


int main(int argc, char const *argv[])
{
    int r = 5;
    srand(current_ms());
    for(int i =0; i < 10; i++) {

        printf("%d\n", rand());
        // printf("%d\n");
    }
    return 0;
}


