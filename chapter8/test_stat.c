#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// int stat(const char *pathname, struct stat *statbuf);
// int fstat(int fd, struct stat *statbuf);


int main(int argc, char const *argv[])
{

    if(argc != 2) {
        printf("格式： %s <dirname>\n", argv[0]);
        return 0;
    }

    struct stat cur_stat;
    // if(stat(argv[1], &cur_stat) < 0 || !S_ISDIR(cur_stat.st_mode)) {
    //     printf("打开的不是文件夹\n");
    //     return 0;
    // }

    int fd = open(argv[1], O_RDONLY, 0);
    char buf[1024];

    struct direct dirbuf;
    int ret = read(fd, (char *) &dirbuf, sizeof(struct direct));
    // printf("d_ino=%ld\n", dirbuf.d_ino);
    // printf("%s\n", dirbuf.d_name);
    // close(fd);

    // printf("files=%ld\n", cur_stat.st_nlink);
    // printf("st_mode=%o\n", cur_stat.st_mode);
    // int ret = read(fd, buf, 1024);

    if(ret == -1) {
        fprintf(stderr, "错误信息：%s\n", strerror(errno));
    }

    printf("fd=%d, ret=%d\n", fd, ret);

    return 0;
}

