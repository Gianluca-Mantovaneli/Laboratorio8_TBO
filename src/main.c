#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
int main()
{
    int N = 1000000; // Number of keys to generate
    int M = 5;       // Number of tests

    // Generate N random keys
    int keys[N];
    for (int i = 0; i < N; i++)
    {
        keys[i] = rand() % N;
    }
    // Create a new tree
    for (int i = 0; i < M; i++)
    {
        Node *root = createNode(keys[0]);
        for (int i = 0; i < N; i++)
        {
            root = insert(root, keys[i]);
        }
        // Print the height of the tree
        printf("Height of the tree: %d\n", height(root));
        // Delete the tree
        deleteTree(root);
    }

    return 0;
}
