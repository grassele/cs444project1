#include <stdio.h>
#include <pthread.h>

void *run_func(void *arg) {
    char *name = arg;

    for (int i = 0; i <= 5; i++) {
        printf("%s: %d\n", name, i);
    }

    return NULL;
}

int main(void) {
    printf("Launching threads\n");

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, run_func, "thread 1");
    pthread_create(&t2, NULL, run_func, "thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads complete!\n");
}

