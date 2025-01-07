#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
    int color; // Red = 1, Black = 0
};

// Sentinel node to represent NIL leaves
struct node* TNULL;

// Create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = TNULL;
    newNode->right = TNULL;
    newNode->color = 1; // New nodes are always red
    return newNode;
}

// Initialize the TNULL node (Black sentinel)
void initializeTNULL() {
    TNULL = (struct node*)malloc(sizeof(struct node));
    TNULL->color = 0; // TNULL is always black
    TNULL->left = NULL;
    TNULL->right = NULL;
    TNULL->parent = NULL;
}

// Left rotate operation
struct node* leftRotate(struct node* root, struct node* x) {
    struct node* y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

    return root;
}

// Right rotate operation
struct node* rightRotate(struct node* root, struct node* x) {
    struct node* y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;

    return root;
}

// Fix the Red-Black Tree after an insertion
struct node* fixInsert(struct node* root, struct node* k) {
    struct node* u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    root = rightRotate(root, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                root = leftRotate(root, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    root = leftRotate(root, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                root = rightRotate(root, k->parent->parent);
            }
        }
        if (k == root) break;
    }
    root->color = 0;
    return root;
}

// Insert a node into the Red-Black Tree
struct node* insert(struct node* root, int data) {
    struct node* node = createNode(data);
    struct node* y = NULL;
    struct node* x = root;

    while (x != TNULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    node->parent = y;
    if (y == NULL) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1; // New nodes are red

    root = fixInsert(root, node);
    return root;
}

// Inorder traversal of the tree
void inorder(struct node* root) {
    if (root != TNULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver code to test the Red-Black Tree
int main() {
    struct node* root = NULL;
    initializeTNULL();  // Initialize the TNULL node

    int choice, value;

    do {
        printf("\nRed-Black Tree Operations\n");
        printf("1. Insert a new node\n");
        printf("2. Left rotate\n");
        printf("3. Right rotate\n");
        printf("4. Inorder traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Node inserted: %d\n", value);
            break;

        case 2:
            printf("Enter value to left rotate: ");
            scanf("%d", &value);
            {
                struct node* node = root;
                while (node != TNULL && node->data != value) {
                    if (value < node->data) {
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                }
                if (node != TNULL) {
                    root = leftRotate(root, node);
                    printf("Left rotation on node %d completed.\n", value);
                } else {
                    printf("Node not found.\n");
                }
            }
            break;

        case 3:
            printf("Enter value to right rotate: ");
            scanf("%d", &value);
            {
                struct node* node = root;
                while (node != TNULL && node->data != value) {
                    if (value < node->data) {
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                }
                if (node != TNULL) {
                    root = rightRotate(root, node);
                    printf("Right rotation on node %d completed.\n", value);
                } else {
                    printf("Node not found.\n");
                }
            }
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
