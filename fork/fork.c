#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
 {
    pid_t id;
    printf("Before fork\n");
    id=fork();
    
     if(id==0)
     {
       printf("child:PPID %d\n",getpid());
       printf("child:PPID %d\n",getppid());
       }
       else
       {
          printf("parent:PID %d\n",getpid());
          printf("parent:PPID %d\n",getppid());
          printf("parent finished\n");
          }
          return 0;
          }
