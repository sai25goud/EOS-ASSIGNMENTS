#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


   int main(int argc,char const *argv[])
   {
       printf("ID:%d\n",getpid());
       printf("parent ID:%d\n",getppid());

       return 0;
   }