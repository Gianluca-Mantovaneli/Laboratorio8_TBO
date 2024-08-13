#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
int main()
{
    int N = 1000000; // Number of keys to generate

    for (int i = 0; i < 10; i++)
    {
        Node *root = createNode(rand() % 10000);
        for (int j = 0; j < N; j++)
        {
            srand(time(0));
            int key = rand() % 10000;
            root = insert(root, key);
        }
        printf("Altura da árvore: %d\n", height(root));
        deleteTree(root);
    }

    return 0;
}
