#if !defined(bst_H)
#define bst_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data);
Node *insert(Node *root, int data);
void deleteTree(Node *root);
Node *search(Node *root, int data);
int height(Node *root);

#endif // bst_H
