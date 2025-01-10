#include <stdio.h>
#include <stdlib.h>

// Red-Black Tree Node Structure
typedef struct Node {
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    int color; // 0 for black, 1 for red
} Node;

// Red-Black Tree Structure
typedef struct RedBlackTree {
    Node* root;
} RedBlackTree;

// Function Declarations
Node* createNode(int data);
RedBlackTree* createRedBlackTree();
void leftRotate(RedBlackTree* tree, Node* x);
void rightRotate(RedBlackTree* tree, Node* y);
void insertFixup(RedBlackTree* tree, Node* z);
void insert(RedBlackTree* tree, int data);
Node* search(Node* root, int value);
void inOrderTraversal(Node* root);
void freeMemory(Node* root);

int main() {
    int choice, value;
    RedBlackTree* tree = createRedBlackTree();
    while (1) {
        printf("\n1. Insertion\n2. Left Rotation\n3. Right Rotation\n4. Display\n5. Exit");
        printf("\nEnter your choice: ");
        switch (choice) {
            case 1: 
                printf("Enter the value to be inserted: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Try again.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                insert(tree, value);
                break;
            case 2: 
                printf("Enter the value to be left rotated: "); 
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Try again.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                {
                    Node* leftRotNode = search(tree->root, value); 
                    if (leftRotNode != NULL) {
                        printf("Performing left rotation on node %d\n", value);
                        leftRotate(tree, leftRotNode); 
                    } else 
                        printf("Node not found!\n"); 
                }
                break; 
            case 3: 
                printf("Enter the value to be right rotated: "); 
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Try again.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                {
                    Node* rightRotNode = search(tree->root, value); 
                    if (rightRotNode != NULL) {
                        printf("Performing right rotation on node %d\n", value);
                        rightRotate(tree, rightRotNode); 
                    } else 
                        printf("Node not found!\n"); 
                }
                break;
            case 4: 
                printf("In-order traversal of the tree:\n");
                inOrderTraversal(tree->root);
                printf("\n");
                break;
            case 5: 
                freeMemory(tree->root);
                free(tree);
                printf("Exiting the program.\n");
                exit(0);
            default: 
                printf("\nWrong selection!!! Try again!!!\n");  
        }
    }
    return 0;
}

// Function Definitions
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->parent = newNode->left = newNode->right = NULL;
    newNode->color = 1; // New nodes are initially red
    printf("Created node with value %d\n", data);
    return newNode;
}

RedBlackTree* createRedBlackTree() {
    RedBlackTree* newTree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    if (newTree == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newTree->root = NULL;
    return newTree;
}

void leftRotate(RedBlackTree* tree, Node* x) {
    if (x == NULL || x->right == NULL) {
        printf("Left rotation not possible for node %d\n", x ? x->data : -1);
        return;
    }
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    printf("Left rotation performed on node %d\n", x->data);
}

void rightRotate(RedBlackTree* tree, Node* y) {
    if (y == NULL || y->left == NULL) {
        printf("Right rotation not possible for node %d\n", y ? y->data : -1);
        return;
    }
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        tree->root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
    printf("Right rotation performed on node %d\n", y->data);
}

void insertFixup(RedBlackTree* tree, Node* z) {
    while (z->parent != NULL && z->parent->color == 1) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != NULL && y->color == 1) {
                z->parent->color = 0; // Black
                y->color = 0; // Black
                z->parent->parent->color = 1; // Red
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = 0; // Black
                z->parent->parent->color = 1; // Red
                rightRotate(tree, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != NULL && y->color == 1) {
                z->parent->color = 0; // Black
                y->color = 0; // Black
                z->parent->parent->color = 1; // Red
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = 0; // Black
                z->parent->parent->color = 1; // Red
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = 0; // Root must be black
    printf("Tree fixed after insertion\n");
}

void insert(RedBlackTree* tree, int data) {
    Node* z = createNode(data);
    Node* y = NULL;
    Node* x = tree->root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        tree->root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    printf("Inserted node with value %d\n", data);
    insertFixup(tree, z);
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

void inOrderTraversal(Node* root) {
    char* colorStr[2] = {"BLACK", "RED"};
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d, %s -> ", root->data, colorStr[root->color]);
        inOrderTraversal(root->right);
    }
}

void freeMemory(Node* root) {
    if (root == NULL)
        return;
    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
}
