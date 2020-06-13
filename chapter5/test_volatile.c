#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static int flag = 1;
void *run(void * arg) {

    while(flag) {

    }

    printf("finish run...\n");
    return NULL;
}

void *stop(void * arg) {

    sleep(2);
    flag = 0;

    printf("finish stop...\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t run_t;
    pthread_create(&run_t, 0, run, NULL);

    pthread_t stop_t;
    pthread_create(&stop_t, 0, stop, NULL);


    pthread_join(run_t, NULL);
    pthread_join(stop_t, NULL);


    return 0;
}
