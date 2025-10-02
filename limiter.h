#include<time.h>

typedef struct {
    int mode; // 0: OFF, 1: BURSTY, 2: STRICT
    int rate;
    int capacidade;
    int tokens;
    double last_update;
} bucket;


bucket *init_bucket(int mode, int rate, int capacidade, int tokens);
int allow_request(bucket *b);