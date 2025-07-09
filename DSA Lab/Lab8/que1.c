#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void printTree(struct Node* root, int space) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    printf("\n%*s%d\n", space, "", root->data);
    printTree(root->left, space);
}

struct Node* findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int val) {
    if (!root) return NULL;
    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        if (!root->left) { struct Node* t = root->right; free(root); return t; }
        if (!root->right) { struct Node* t = root->left; free(root); return t; }
        struct Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    while (n--) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nTree:\n");
    printTree(root, 0);

    printf("\nInorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);

    int choice;
    do {
        printf("\n\nDelete a node? (1=Yes, 0=No): ");
        scanf("%d", &choice);
        if (choice) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            struct Node* t = root;
            while (t) {
                if (val == t->data) break;
                t = val < t->data ? t->left : t->right;
            }
            if (!t) printf("Value not found!\n");
            else {
                root = deleteNode(root, val);
                printf("Deleted %d.\n", val);
                printf("\nTree after deletion:\n");
                printTree(root, 0);
                printf("\nInorder: "); inorder(root);
            }
        }
    } while (choice);

    return 0;
}
