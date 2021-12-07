#include <stdio.h>
#include <pthread.h>


int count = 10;
pthread_mutex_t mutexcount;
pthread_mutexattr_t mutexcountAttr;

void square()
{
    printf("IncThread: Grabbing mutex inside function square\n");
    pthread_mutex_lock(&mutexcount);
    printf("IncThread: Inside cs inside square\n");
    count = count * count;
    pthread_mutex_unlock(&mutexcount);
    printf("IncThread: Releasing mutex inside function square\n");
}

void *inc_thread(void *arg)
{
    while (1)
    {
        //LOCK
        printf("IncThread: Grabbing mutex\n");
        pthread_mutex_lock(&mutexcount);
        printf("IncThread: Inside cs\n");
        count++;
        square();
        printf("IncThread:%d\n",count);
        pthread_mutex_unlock(&mutexcount);
        printf("IncThread: Releasing mutex \n");
        //UNLOCK
    }
    
}
void *dec_thread(void *arg)
{
    while (1)
    {
        //LOCK 
        printf("DecThread: Grabbing mutex\n");
        pthread_mutex_lock(&mutexcount);
        printf("DecThread: Inside cs\n");
        count--;
        square();
        printf("DecThread:%d\n",count);
        pthread_mutex_unlock(&mutexcount);
        printf("DecThread: Grabbing mutex\n");
        //UNLOCK
    }
    
}

int main(int argc, char const *argv[])
{

    
    pthread_t incID, decID;
    printf("main thread:before creating hello thread\n");
   // pthread_mutex_init(&mutexcount,NULL);
    pthread_mutexattr_init(&mutexcountAttr);
    pthread_mutexattr_settype(&mutexcountAttr, PTHREAD_MUTEX_RECURSIVE);



    pthread_mutex_init(&mutexcount,&mutexcountAttr);
    pthread_create(&incID, NULL, inc_thread, "NULL");
    pthread_create(&decID, NULL, dec_thread, "NULL");

    
      pthread_join(incID,NULL);
      pthread_join(decID,NULL);
      pthread_mutex_destroy(&mutexcount);
      printf("main thread:After creating hello thread\n");

      return 0;
  }