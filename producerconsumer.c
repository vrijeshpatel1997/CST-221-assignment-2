// Vrijesh Patel
// CST 221
// This is my own work

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
// global variable
#define N 10 // numbers to produce
int produce();
void put();
void *producer();
void *consumer();
void consume();
int get();
int buffer[N]; // item numbers in buffer

int Product;

void *producer() { // produces the data
	int i;
for(; ;)   { // loop to producer
		i = produce();
		put(i); // put product result in i variable  as its generated go to sleep
		sleep(1);
	}
}

void *consumer() {
	int i;
for(; ;)  {
		i = get();
		consume(i);// consume data that is resulted in i variable if data is consume start sleep
		sleep(1);
	}
}

int produce() { // increment Product
	return Product + 1;
}

void consume(int i) { // print consumer thread
	printf("Consumer  : %i\n",i);
}

void put(int i) { // print producer thread
	Product = i;
	printf("Producer : %d\n", i);
	return;
}

int get() {
	return Product; // return product
}

void main() {
	pthread_t threads[2];
 	pthread_create(&threads[0], 0, consumer, 0); // create thread 
 	pthread_create(&threads[1], 0, producer, 0);
 	pthread_join(threads[0], 0); // join thread waiting calls parameter added identifier of thread to wait for
	pthread_join(threads[1], 0);

}
