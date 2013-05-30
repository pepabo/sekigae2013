#if 0
#!/bin/bash
o=`basename $0`
o="__${o%.*}"
CFLAGS="-O0 -std=gnu99 -W -lpthread -Wall"
LDFLAGS="-pie"
gcc ${CFLAGS} ${LDFLAGS} -o $o $0 && ./$o $*; exit
#endif

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t mutex;

void * do_sekigae(void *arg) {
    char *name = (char *)arg;

    for( int i = 0; i < 100000000; i++ );
    pthread_mutex_lock(&mutex);
    puts(name);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {

    pthread_t thread[4];

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread[0], NULL, do_sekigae, "kitak");
    pthread_create(&thread[1], NULL, do_sekigae, "okkun");
    pthread_create(&thread[2], NULL, do_sekigae, "gussan");
    pthread_create(&thread[3], NULL, do_sekigae, "keoken");

    for( int i = 0; i < 4; i++ ) {
        pthread_join(thread[i], NULL);
    }

    exit(0);
}

