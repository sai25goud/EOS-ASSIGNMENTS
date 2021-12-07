#include <stdio.h>
#include <pthread.h>


int count = 10;
pthread_mutex_t mutexcount;

void *inc_thread(void *arg)
{
    while (1)
    {
        //LOCK
        pthread_mutex_lock(&mutexcount);
        count++;
        printf("IncThread:%d\n",count);
        pthread_mutex_unlock(&mutexcount);
        //UNLOCK
    }
    
}
void *dec_thread(void *arg)
{
    while (1)
    {
        //LOCK
        pthread_mutex_lock(&mutexcount);
        count--;
        printf("DecThread:%d\n",count);
        pthread_mutex_unlock(&mutexcount);
        //UNLOCK
    }
    
}

int main(int argc, char const *argv[])
{

    
    pthread_t incID, decID;
    printf("main thread:before creating hello thread\n");
    pthread_mutex_init(&mutexcount,NULL);
    pthread_create(&incID, NULL, inc_thread, "NULL");
    pthread_create(&decID, NULL, dec_thread, "NULL");

    
      pthread_join(incID,NULL);
      pthread_join(decID,NULL);
      pthread_mutex_destroy(&mutexcount);
      printf("main thread:After creating hello thread\n");

      return 0;
  }