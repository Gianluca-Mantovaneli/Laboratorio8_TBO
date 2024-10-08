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
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data == root->data)
    {
        // Caso os dados já existam, não inserimos o novo nó e liberamos a memória alocada.
        return root;
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

Node *rotateRight(Node *node)
{
    Node *aux = node->left;
    node->left = aux->right;
    aux->right = node;
    return aux;
}

Node *rotateLeft(Node *node)
{
    Node *aux = node->right;
    node->right = aux->left;
    aux->left = node;
    return aux;
}

Node *insereWithRotation(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data == root->data)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = insereWithRotation(root->left, data);

        // Verifica se precisa rotacionar
        if (height(root->left) - height(root->right) > 1)
        {
            root = rotateRight(root);
        }
    }
    else
    {
        root->right = insereWithRotation(root->right, data);

        // Verifica se precisa rotacionar
        if (height(root->right) - height(root->left) > 1)
        {
            root = rotateLeft(root);
        }
    }

    return root;
}
