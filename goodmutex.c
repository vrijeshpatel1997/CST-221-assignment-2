#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



int product = 0;
pthread_mutex_t mutex;




void *counter(){

  int x, tmp;

  for(x=0; x < 100000; ++x)
  {
    pthread_mutex_lock(&mutex);


    tmp = product;
    tmp = tmp + 1;
    product = tmp;

  pthread_mutex_unlock(&mutex);

  }


}


int main(int argc, char* argv[])
{

pthread_t tid1, tid2;

pthread_mutex_init(&mutex, NULL);

if(pthread_create(&tid1, NULL, &counter, NULL)!= 0 ){

  return 1;
}


if(pthread_create(&tid2, NULL, &counter, NULL)!= 0){

  return 2;
}



if(pthread_join(tid1, NULL)!= 0 )
{

return 3;
}

if(pthread_join(tid2, NULL)!= 0)
{

return 4;
}
pthread_mutex_destroy(&mutex);
printf("Number of product is %d\n", product );

  return 0 ;

    }

    // gcc bank.c -lpthread
    // ./a.out
