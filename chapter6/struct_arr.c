#include <stdio.h>

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    {"hello", 0},
    {"world", 1}
};

#define KEYSIZE (sizeof(keytab)/sizeof(keytab[0]))

struct hole {
       char c;
       int i;
};

int main(int argc, char const *argv[])
{
    for(int i = 0; i < KEYSIZE; i++) {
        printf("word:%s, count:%d\n", keytab[i].word, keytab[i].count);
    }
    printf("size=%ld\n", KEYSIZE);
    printf("hole size: %ld", sizeof(struct hole));
    return 0;
}
