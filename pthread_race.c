#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
/**
 * THESE DEFINE VALUES CANNOT BE CHANGED.
 * DOING SO WILL CAUSE POINTS TO BE DEDUCTED
 * FROM YOUR GRADE
 */
 /** BEGIN VALUES THAT CANNOT BE CHANGED */
#define MAX_THREADS 36
#define MAX_ITERATIONS 22
/** END VALUES THAT CANNOT BE CHANGED */


/**
 * use this struct as a parameter for the
 * nanosleep function.
 * For exmaple : nanosleep(&ts, NULL);
 */
struct timespec ts = {0, 150000};

void* thread_func(void* arg) {
    int idx = *((int*) arg);
    printf("Thread Id : %d\n",idx);
}

int main(int argc, char** argv) {
    pthread_t ids[10];

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        int idx = i;
        pthread_create(&ids[i], NULL, thread_func, (void*) &idx);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(ids[i], NULL);
    }

    return 0;
}
