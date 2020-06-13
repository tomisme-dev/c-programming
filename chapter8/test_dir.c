#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
// DIR *opendir(const char *name);


int main(int argc, char const *argv[])
{
    if(argc != 2) {
        printf("格式： %s <dirname>\n", argv[0]);
        return 0;
    }


    DIR *dir = opendir(argv[1]);
    struct dirent *dir_e =  readdir(dir);
    while((dir_e =  readdir(dir)) != NULL) {
        printf("d_name=%s\n", dir_e->d_name);
    }
    
    
    closedir(dir);
    return 0;
}

