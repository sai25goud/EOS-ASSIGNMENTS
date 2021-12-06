#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;

    printf("before fork\n");
    id = fork();
    printf("after fork\n");
    if (0 == id)
    {
        printf("child:before exec\n");
        execl("/home/sai25goud/Documents/eos/pid/pid", "/home/sai25goud/Documents/eos/pid/pid", NULL);
        printf("child:after exec\n");
    }
    else
    {
        printf("parent\n");
    }
    printf("program exited\n");
    return 0;
}
