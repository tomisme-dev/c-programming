#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *name = "end";
    int fd = open("a.txt", O_RDWR);
    lseek(fd, 2, SEEK_SET);
    write(fd, name, strlen(name));
    close(fd);
    return 0;
}
