#include "bst.h"

// @brief Create a new node
// @param data The data to be stored in the node
// @return The new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// @brief Insert a new node into the tree
// @param root The root of the tree
// @param data The data to be stored in the new node
// @return The new root of the tree
Node *insert(Node *root, int data)
{
    Node *newNode = createNode(data);
    if (root == NULL)
    {
        return newNode;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// @brief Delete the tree
// @param root The root of the tree
void deleteTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// @brief Search for a node in the tree
// @param root The root of the tree
// @param data The data to be searched
// @return The node with the data
Node *search(Node *root, int data)
{
    Node *aux = root;
    if (root == NULL)
    {
        return NULL;
    }
    if (aux->data == data)
    {
        return aux;
    }
    if (data < root->data)
    {
        aux = search(root->left, data);
    }
    else
    {
        aux = search(root->right, data);
    }

    return aux;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}
