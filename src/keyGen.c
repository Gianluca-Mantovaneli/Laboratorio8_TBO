#include "keyGen.h"

int *generateKeys(int N)
{
    int *keys = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        keys[i] = rand() % N;
    }
    return keys;
}

void destroyKeys(int *keys)
{
    free(keys);
}
