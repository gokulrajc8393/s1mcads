#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createnode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Insert node at the front
void insertAtFront(struct node** head, int data) {
    struct node* newNode = createnode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert node at the end
void insertAtLast(struct node** head, int data) {
    struct node* newNode = createnode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert node at a particular position
void insertAtParticularPosition(struct node** head, int data, int position) {
    struct node* newNode = createnode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is out of bounds\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Traversal of the list
void traverse(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search a node
void search(struct node* head, int value) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found in the list.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", value);
}

int main() {
    struct node* head = NULL;
    int ch, data, position;

    do {
        printf("Linked List Operations\n");
        printf("1. Creation\n");
        printf("2. Insert Node At Front\n");
        printf("3. Insert Node At Last\n");
        printf("4. Insert Node At Particular Position\n");
        printf("5. Traversal\n");
        printf("6. Searching\n");
        printf("7. Exit\n");
        printf("\nChoose an operation: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter the value to create a node: ");
                scanf("%d", &data);
                head = createnode(data);  // Create the first node
                printf("Node with value %d created.\n", data);
                break;

            case 2:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                printf("Node with value %d inserted at the front.\n", data);
                break;

            case 3:
                printf("Enter the value to insert at the last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                printf("Node with value %d inserted at the last.\n", data);
                break;

            case 4:
                printf("Enter the value to insert at a particular position: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtParticularPosition(&head, data, position);
                break;

            case 5:
                printf("Traversing the list:\n");
                traverse(head);
                break;

            case 6:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                search(head, data);
                break;

            case 7:
                printf("Exiting the program.\n");
                break;

            default:
                printf("\nEnter a valid option.\n\n");
                break;
        }
    } while(ch != 7);

    return 0;
}
