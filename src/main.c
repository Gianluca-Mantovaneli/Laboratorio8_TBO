#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "keyGen.h"
int main()
{
    int N = 1000000; // Number of keys to generate
    int M = 10;      // Number of tests
    double soma, soma2 = 0;

    // Create a new tree
    for (int i = 0; i < M; i++)
    {
        // Generate the keys
        int *keys = generateKeys(N);
        Node *root = createNode(keys[0]);
        Node *root2 = createNode(keys[0]);

        // Insert the keys into the tree
        for (int i = 0; i < N; i++)
        {
            root = insert(root, keys[i]);
            root2 = insereWithRotation(root2, keys[i]);
        }

        soma += height(root);
        soma2 += height(root2);

        // Delete the tree
        deleteTree(root);
        deleteTree(root2);
        destroyKeys(keys);
    }
    printf("Average height: %f\n", soma / M);
    printf("Average height with rotation: %f\n", soma2 / M);

    return 0;
}
