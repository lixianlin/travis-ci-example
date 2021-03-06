#include <stdio.h>
#include <pthread.h>

#define THREAD_NUM 5

void* threadEntry(void* data)
{
    printf("Hello from thread(id=0x%lx)!\n", pthread_self());
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t threads[THREAD_NUM];
    int i, j;

    for(i = 0; i < THREAD_NUM; ++i) {
        pthread_create(&threads[i], NULL, threadEntry, NULL);
    }

    for (j = 0; j < THREAD_NUM; ++j) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}
