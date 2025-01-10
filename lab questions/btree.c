#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 3 // Maximum keys in a node (t-1 where t is the minimum degree)
#define MIN_KEYS 1 // Minimum keys in a node (ceil(t/2) - 1)
#define MAX_CHILDREN (MAX_KEYS + 1) // Maximum children in a node (t)

typedef struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode* children[MAX_CHILDREN];
    int numKeys;
    int isLeaf;
} BTreeNode;

// Create a new BTree node
BTreeNode* createNode(int isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Split a child node
void splitChild(BTreeNode* parent, int index, BTreeNode* child) {
    BTreeNode* newChild = createNode(child->isLeaf);
    newChild->numKeys = MIN_KEYS;

    for (int i = 0; i < MIN_KEYS; i++) {
        newChild->keys[i] = child->keys[i + MIN_KEYS + 1];
    }

    if (!child->isLeaf) {
        for (int i = 0; i < MIN_KEYS + 1; i++) {
            newChild->children[i] = child->children[i + MIN_KEYS + 1];
        }
    }

    child->numKeys = MIN_KEYS;

    for (int i = parent->numKeys; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }

    parent->children[index + 1] = newChild;

    for (int i = parent->numKeys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }

    parent->keys[index] = child->keys[MIN_KEYS];
    parent->numKeys++;
}

// Insert into a non-full node
void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }

        if (node->children[i + 1]->numKeys == MAX_KEYS) {
            splitChild(node, i + 1, node->children[i + 1]);

            if (key > node->keys[i + 1]) {
                i++;
            }
        }

        insertNonFull(node->children[i + 1], key);
    }
}

// Insert a key into the B-tree
void insert(BTreeNode** root, int key) {
    BTreeNode* r = *root;
    if (r->numKeys == MAX_KEYS) {
        BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = r;
        splitChild(newRoot, 0, r);

        int i = 0;
        if (newRoot->keys[0] < key) {
            i++;
        }
        insertNonFull(newRoot->children[i], key);
        *root = newRoot;
    } else {
        insertNonFull(r, key);
    }
}

// Search for a key in the B-tree
BTreeNode* search(BTreeNode* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }

    if (i < root->numKeys && key == root->keys[i]) {
        return root;
    }

    if (root->isLeaf) {
        return NULL;
    }

    return search(root->children[i], key);
}

// Traverse the B-tree in-order
void traverse(BTreeNode* root) {
    if (root == NULL) return;
    int i;
    for (i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }

    if (!root->isLeaf) {
        traverse(root->children[i]);
    }
}

int main() {
    BTreeNode* root = createNode(1);
    int choice, key;

    while (1) {
        printf("\nB-Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key %d found in the B-tree.\n", key);
                } else {
                    printf("Key %d not found in the B-tree.\n", key);
                }
                break;

            case 3:
                printf("Traversal of the B-tree: \n");
                traverse(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
