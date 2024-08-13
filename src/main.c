#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "keyGen.h"
int main()
{
    int N = 1000000; // Number of keys to generate
    int M = 5;       // Number of tests

    // Create a new tree
    for (int i = 0; i < M; i++)
    {
        // Generate the keys
        int *keys = generateKeys(N);
        Node *root = createNode(keys[0]);

        // Insert the keys into the tree
        for (int i = 0; i < N; i++)
        {
            root = insert(root, keys[i]);
        }

        // Print the height of the tree
        printf("Height of the tree: %d\n", height(root));

        // Delete the tree
        deleteTree(root);
        destroyKeys(keys);
    }

    return 0;
}
