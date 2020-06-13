#include <unistd.h>


int main(int argc, char const *argv[])
{
    unlink("a.txt");
    return 0;
}
