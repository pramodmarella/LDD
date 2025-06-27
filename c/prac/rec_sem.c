#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t bin_sem;

void* funcB(void *arg) {
    printf("funcB is executing\n");
    sem_wait(&bin_sem);  // Acquire (wait) on semaphore
    printf("funcB has acquired the semaphore\n");
    sem_post(&bin_sem);  // Release (signal) the semaphore
    return NULL;
}

void* funcA(void *arg) {
    printf("funcA is executing\n");
    sem_wait(&bin_sem);  // Acquire the semaphore
    funcB(NULL);          // Call funcB, which also tries to acquire the semaphore
    sem_post(&bin_sem);   // Release the semaphore
    return NULL;
}

int main() {
    sem_init(&bin_sem, 0, 1);  // Initialize binary semaphore (value 1)
    
    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, funcA, NULL);
    pthread_create(&threadB, NULL, funcB, NULL);
    
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    
    sem_destroy(&bin_sem);  // Clean up semaphore
    return 0;
}

