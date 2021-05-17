#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREADNUMBER 16

// Vrijesh patel
// This is my own work.

sem_t semaphore;

void* routine(void* args) {
    printf("(%d)  Waiting to ride in roller coster ride\n", *(int*)args);
    sem_wait(&semaphore);
    printf("(%d)your now on the roller coster  ride\n", *(int*)args);
    sleep(rand() % 5 + 1);
    printf("(%d) ride is now over getting off\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREADNUMBER];
    sem_init(&semaphore, 0, 10);
    int i;
    for (i = 0; i < THREADNUMBER; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("eroor cant  create thread");
        }
    }

    for (i = 0; i < THREADNUMBER; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Error cant  join thread");
        }
    }
    sem_destroy(&semaphore);
    return 0;
}
