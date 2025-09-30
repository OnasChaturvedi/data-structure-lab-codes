#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* createTree() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct Node* node = newNode(x);

    printf("Enter left child of %d:\n", x);
    node->left = createTree();

    printf("Enter right child of %d:\n", x);
    node->right = createTree();

    return node;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

void printLevel(struct Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printLevel(root, i);
}

int main() {
    struct Node* root = NULL;
    printf("Create the binary tree:\n");
    root = createTree();

    printf("\nLevel-order traversal of the tree:\n");
    levelOrder(root);

    return 0;
}
