#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int product = 0;





void *counter(){

  int x, tmp;

  for(x=0; x < 1000000; ++x)
  {

    tmp = product;
    tmp = tmp + 1;
    product = tmp;



  }


}


int main(int argc, char* argv[])
{

pthread_t tid1, tid2;


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

printf("Number of product is %d\n", product );

  return 0 ;

    }

    // gcc bank.c -lpthread
    // ./a.out
