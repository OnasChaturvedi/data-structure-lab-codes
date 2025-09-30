#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void inorderIterative(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void postorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }

    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);
}

void preorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void printParent(struct Node* root, int key) {
    if (root == NULL) return;

    if ((root->left && root->left->data == key) ||
        (root->right && root->right->data == key)) {
        printf("Parent of %d is %d\n", key, root->data);
        return;
    }

    printParent(root->left, key);
    printParent(root->right, key);
}

int getHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool printAncestors(struct Node* root, int key) {
    if (root == NULL) return false;

    if (root->data == key)
        return true;

    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return true;
    }
    return false;
}

int countLeaves(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    /*
             1
            / \
           2   3
          / \   \
         4   5   6
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Inorder (Iterative): ");
    inorderIterative(root);
    printf("\n");

    printf("Preorder (Iterative): ");
    preorderIterative(root);
    printf("\n");

    printf("Postorder (Iterative): ");
    postorderIterative(root);
    printf("\n");

    printParent(root, 5);

    printf("Height of tree: %d\n", getHeight(root));

    printf("Ancestors of 5: ");
    printAncestors(root, 5);
    printf("\n");

    printf("Leaf nodes count: %d\n", countLeaves(root));

    return 0;
}
