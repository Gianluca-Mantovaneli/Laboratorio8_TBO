#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
int main()
{
    int N = 10000; // Number of keys to generate
    Node *root = createNode(rand() % 10000);

    for (int i = 0; i < N; i++)
    {
        srand(time(0));
        int key = rand() % 10000;
        root = insert(root, key);
    }
    printf("Altura da árvore: %d\n", height(root));
    deleteTree(root);
    return 0;
}
