#ifndef LIMITER_H
#define LIMITER_H

typedef struct {
    int mode; // 0: OFF, 1: BURSTY, 2: STRICT
    int rate;
    int capacidade;
    int tokens;
    double last_update;
} bucket;

double get_time();
bucket *init_bucket(int mode, int rate, int capacidade);
void update_bucket(bucket *b, int mode, int rate, int capacidade);
int allow_request(bucket *b);

#endif