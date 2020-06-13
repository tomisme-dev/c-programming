#include <stdio.h>

struct
{
    unsigned int is_keyword : 2;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} flags;


int main(int argc, char const *argv[])
{
    flags.is_keyword = 0;
    flags.is_extern = 1; 
    flags.is_static = 0;

    char *ptr = (void *)&flags;

    printf("flag: %d", (flags.is_keyword | flags.is_extern));
    
    return 0;
}
