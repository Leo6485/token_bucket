#include <stdio.h>
#include <unistd.h>
#include <limiter.h>
#include <sys.time.h>

bucket *init_bucket(int mode, int rate, int capacidade) {
    bucket *b = malloc(sizeof(bucket));
    b->mode = mode;
    b-rate = rate;
    b->capacidade = mode != 2 ? capacidade : rate;
    b->last_request = 0;
}

void update_bucket
double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * tv.tv_usec / 1e6;
}

int allow_request(bucket *b) {
    if (!mode) return 1;

    now = get_time()
    delta = now - b->last_update;
    refil = delta * b->rate;
    b->tokens = (b->tokens + refil <= b->capacidade) b->tokens + refil : b->capacidade;
    b->last_update = now;

    if (b->tokens) {
        b->token--;
        return 1
    }

    return 0;
}


int main() {
    return 0;
}