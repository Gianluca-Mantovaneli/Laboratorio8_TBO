#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "keyGen.h"

int main()
{
    int N = 1000000;            // Number of keys to generate
    int M = 10;                 // Number of tests
    double soma = 0, soma2 = 0; // Inicializa as variáveis

    for (int i = 0; i < M; i++)
    {
        // Generate the keys
        int *keys = generateKeys(N);
        if (keys == NULL)
        {
            fprintf(stderr, "Erro ao gerar chaves.\n");
            return 1;
        }

        Node *root = createNode(keys[0]);
        Node *root2 = createNode(keys[0]);

        for (int j = 1; j < N; j++)
        {
            root = insert(root, keys[j]);
            root2 = insereWithRotation(root2, keys[j]);
        }

        soma += height(root);
        soma2 += height(root2);

        // Delete the tree
        deleteTree(root);
        deleteTree(root2);
        destroyKeys(keys);
    }

    printf("Average height: %.2f\n", soma / M);
    printf("Average height with rotation: %.2f\n", soma2 / M);

    return 0;
}
