#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int contains(const Node* root, int value)
{
    // Waiting to be implemented
    if (!root) return 0;
    else
    {
        if (root->value < value)
        {
            return contains(root->right, value);
        }
        else if (root->value > value)
        {
            return contains(root->left, value);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

#ifndef RunTests
int main()
{
    Node n1 = { n1.value = 1, n1.left = NULL, n1.right = NULL };
    Node n3 = { n3.value = 3, n3.left = NULL, n3.right = NULL };
    Node n2 = { n2.value = 2, n2.left = &n1, n2.right = &n3 };

    printf("%d", contains(&n2, 3));
}
#endif

