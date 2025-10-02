#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "limiter.h"

int main() {
    bucket *b = init_bucket(1, 5, 10);
    printf("Modo: %d, Rate: %d, Capacidade: %d\n\n", b->mode, b->rate, b->capacidade);

    printf("tokens ao iniciar: %d\n", b->tokens);
    for (int i = 0; i < 12; i++) {
        if (allow_request(b) == 200)
            printf("200 OK - tokens: %d\n", b->tokens);
        else
            printf("429 Too Many Requests - tokens: %d\n", b->tokens);

        usleep(100000);
    }

    update_bucket(b, 2, 1, 1);
    printf("Bucket atualizado para o modo STRICT, rate: 1\n");
    printf("tokens após atualizar: %d\n", b->tokens);
    for (int i = 0; i < 5; i++) {
        if (allow_request(b) == 200)
            printf("200 OK - tokens: %d\n", b->tokens);
        else
            printf("429 Too Many Requests - tokens: %d\n", b->tokens);

        usleep(100000);
    }
    free(b);
    return 0;
}
