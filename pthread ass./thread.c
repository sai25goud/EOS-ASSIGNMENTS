#include<stdio.h>
#include<pthread.h>

void *hello_thread(void *arg)
{
   printf("Hello thread\n");
}
void *bye_thread(void *arg)
{
    printf("Bye thread\n");
}
  int main(int argc,char const *argv[])
  {
      pthread_t helloID;
      pthread_t byeID;
      printf("main thread:Before creating hello thread\n");
      printf("main thread:Before creating bye thread\n");

      pthread_create(&helloID,NULL,hello_thread,NULL);
      pthread_join(helloID,NULL);
      pthread_create(&byeID,NULL,bye_thread,NULL);
      pthread_join(byeID,NULL);

      printf("main thread:After creating hello thread\n");
       printf("main thread:After creating bye thread\n");
      return 0;
  }