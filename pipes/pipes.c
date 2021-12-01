#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

 int main(int argc,char const *argv[])
 {
     unsigned char buff[16];
     pid_t id;
     int fd[2];
     pipe(fd);

     id=fork();
     if(id==0)
     {
         close(fd[1]);
         printf("child:reading data\n");
         read(fd[0],buff,16);
         printf("child read:%s\n",buff);
     }
     else{
         close(fd[0]);
         printf("parent:writing data\n");
         write(fd[1],"DESD\n", 5);
         printf("parent:writing done\n");
     }
     return 0;
 }