#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limiter.h>
#include <sys/time.h>







double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1e6;
}


bucket *init_bucket(int mode, int rate, int capacidade) {
    bucket *b = malloc(sizeof(bucket));
    b->mode = mode;
    b->rate = rate;
    b->capacidade = mode != 2 ? capacidade : rate;
    b->last_update = get_time();
    b->tokens = b->capacidade;

    return b;
}

void update_bucket(bucket *b, int mode, int rate, int capacidade) {
    b->mode = mode;
    b->rate = rate;
    b->capacidade = mode != 2 ? capacidade : rate;
    b->last_update = get_time();
    b->tokens = b->capacidade;
}

int allow_request(bucket *b) {
    if (!b->mode) return 200;

    double now = get_time();
    double delta = now - b->last_update;

    b->tokens += delta * b->rate;
    if (b->tokens > b->capacidade) {
        b->tokens = b->capacidade;
    }

    b->last_update = now;

    if (b->tokens > 0) {
        b->tokens--;
        return 200;
    }

    return 429;
}


int main() {
    return 0;
}