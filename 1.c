#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* FindMin(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left) {
        return FindMin(node->left);
    } else {
        return node;
    }
}

struct Node* FindMax(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->right) {
        return FindMax(node->right);
    } else {
        return node;
    }
}

struct Node* Insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* temp;
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data > node->data) {
        node->right = Insert(node->right, data);
    } else if (data < node->data) {
        node->left = Insert(node->left, data);
    }
    return node;
}

struct Node* Delete(struct Node* node, int data) {
    struct Node* temp;
    if (node == NULL) {
        printf("Element not found\n");
    } else if (data < node->data) {
        node->left = Delete(node->left, data);
    } else if (data > node->data) {
        node->right = Delete(node->right, data);
    } else {
        if (node->right && node->left) {
            temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        } else {
            temp = node;
            if (node->left == NULL) {
                node = node->right;
            } else if (node->right == NULL) {
                node = node->left;
            }
            free(temp);
        }
    }
    return node;
}

struct Node* Find(struct Node* node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data > node->data) {
        return Find(node->right, data);
    } else if (data < node->data) {
        return Find(node->left, data);
    } else {
        return node;
    }
}

void Inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    Inorder(node->left);
    printf("%4d", node->data);
    Inorder(node->right);
}

void Preorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%4d", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

int main() {
    struct Node* root = NULL;
    struct Node* temp;
    int ch;
    while (1) {
        printf("\n1. Insert\t2. Delete\t3. Inorder\n4. Preorder\t5. Postorder\t6. FindMin\n7. FindMax\t8. Search\t9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &ch);
                root = Insert(root, ch);
                printf("\nElements in BST are: ");
                Inorder(root);
                break;
            case 2:
                printf("\nEnter element to be deleted: ");
                scanf("%d", &ch);
                root = Delete(root, ch);
                printf("\nAfter deletion, elements in BST are: ");
                Inorder(root);
                break;
            case 3:
                printf("\nInorder traversal is: ");
                Inorder(root);
                break;
            case 4:
                printf("\nPreorder traversal is: ");
                Preorder(root);
                break;
            case 5:
                printf("\nPostorder traversal is: ");
                // You need to implement the Postorder function for this case.
                break;
            case 6:
                temp = FindMin(root);
                printf("\nMinimum element is: %d", temp->data);
                break;
            case 7:
                temp = FindMax(root);
                printf("\nMaximum element is: %d", temp->data);
                break;
            case 8:
                printf("\nEnter element to be searched: ");
                scanf("%d", &ch);
                temp = Find(root, ch);
                if (temp == NULL) {
                    printf("Element is not found\n");
                } else {
                    printf("Element %d is found\n", temp->data);
                }
                break;
            case 9:
                exit(0);
            default:
                printf("\nEnter correct choice\n");
                break;
        }
    }
    return 0;
}