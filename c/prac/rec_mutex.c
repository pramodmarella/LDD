#include <pthread.h>
#include <stdio.h>

// Define a recursive mutex
pthread_mutex_t recursive_mutex = PTHREAD_MUTEX_INITIALIZER;

void funcB() {
    printf("funcB is executing\n");
    pthread_mutex_lock(&recursive_mutex);  // Lock again (recursive)
    printf("funcB has locked the mutex again\n");
    pthread_mutex_unlock(&recursive_mutex); // Unlock once
    printf("funcB has unlocked the mutex\n");
}

void funcA() {
    printf("funcA is executing\n");
    pthread_mutex_lock(&recursive_mutex);  // Lock the mutex
    printf("funcA has locked the mutex\n");
    funcB();  // Call funcB, which locks the mutex again
    pthread_mutex_unlock(&recursive_mutex); // Unlock the mutex
    printf("funcA has unlocked the mutex\n");
}

int main() {
    funcA();
    return 0;
}

