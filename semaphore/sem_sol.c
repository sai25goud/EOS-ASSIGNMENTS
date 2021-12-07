#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


int count = 10;
sem_t semcount;

void *inc_thread(void *arg)
{
    while (1)
    {
        sem_wait(&semcount);
        count++;
        printf("IncThread:%d\n",count);
        sem_post(&semcount);
    }
    
}
void *dec_thread(void *arg)
{
    while (1)
    {
        sem_wait(&semcount);
        count--;
        printf("DecThread:%d\n",count);
        sem_post(&semcount);
    }
    
}

int main(int argc, char const *argv[])
{

    
    pthread_t incID, decID;
    printf("main thread:before creating hello thread\n");
    sem_init(&semcount,0,1);
    pthread_create(&incID, NULL, inc_thread, "NULL");
    pthread_create(&decID, NULL, dec_thread, "NULL");

    
      pthread_join(incID,NULL);
      pthread_join(decID,NULL);
      
      printf("main thread:After creating hello thread\n");
      sem_destroy(&semcount);
      return 0;
  }