#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 

int main(int argc, char const *argv[])
{   
    char buf[50];
    FILE *f1,*f2;
    int i;
    int fd_r;                                  
    int fd_w;
    for(i=1;i<argc;i++)
    {
        
        f1=argv[i];
        f2=argv[i+1];
    
    fd_r=open(f1,O_RDWR,S_IRUSR | S_IWUSR);          
    
   
    
    if (fd_r == -1)
    {
        perror("error-->Source not present \n");              
        printf("%d",errno);
        exit(EXIT_FAILURE);
    
    }  
   
    fd_w=open(f2,O_WRONLY,S_IRUSR|S_IWUSR);
    
    if (fd_w == -1)
    {
        fd_w=open(f2,O_CREAT,S_IRUSR|S_IWUSR);
    
    }  
   
    
     do 
     {
    read(fd_r,buf,sizeof(buf));              
     }while(0);
    
    write(fd_w,buf,sizeof(buf));
    
    close(fd_r);
    close(fd_w);
    }
    return 0;
}
