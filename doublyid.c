#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* create(struct node *head);
struct node* insertbeg(struct node *head);
struct node* insertlast(struct node *head);
struct node* deletebeg(struct node *head);
struct node* deletelast(struct node *head);
void traverse(struct node *head);

void main() 
{
    struct node *head = NULL;
    int ch, item;
    printf("Creating a linked list:\n");
    head=create(head);
    while(1)
    {
        printf("\nMENU\n");
        printf("\n1.Insert a node at beginning\n2.Insert a node at end\n3.Delete a node from beginning\n4.Delete a node from end\n5.Traverse\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);   
        switch (ch) 
        {
           case 1:
		   head = insertbeg(head);
		   break;         
           case 2:
		   head = insertlast(head);
		   break;
	   case 3:
		   head = deletebeg(head);
		   break; 
	   case 4:
		   head = deletelast(head);
		   break; 
           case 5:
		   traverse(head);
		   break;
           case 6:
           	exit(0);
           default:
           	printf("Invalid choice. Please enter 1-6\n");
        }
     
    }
}

struct node* create(struct node *head)
{
    int n, item, i;
    struct node *temp, *first;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of nodes should be greater than zero.\n");
        return head;
    }
    printf("Enter the item for node 1: ");
    scanf("%d", &item);
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) 
    {
        printf("Memory insufficient\n");
        exit(1);
    }
    head->prev=NULL;
    head->data = item;
    head->next = NULL;
    first = head;
    for (i = 2; i <= n; i++) 
    {
        printf("Enter the item for node %d: ", i);
        scanf("%d", &item);
        temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            printf("Memory insufficient\n");
            break;
        }
        temp->data = item;
        temp->next = NULL;
        temp->prev=first;
        first->next = temp;
        first = temp;
    }
    return head;
}

struct node* insertbeg(struct node *head) 
{
    int item;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory insufficient\n");
        return head;
    }
    printf("Enter the item you want to insert: ");
    scanf("%d", &item);
    temp->data = item;
    if(head == NULL)
    {
      temp->next = NULL;
      temp->prev = NULL;
    }
    else
    {
      temp->prev = NULL;
      temp->next = head;
      head->prev = temp;
    }
    head = temp;
    printf("One node is inserted at the beginning\n");
    return head;
}

struct node* insertlast(struct node *head) 
{
    int item;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory insufficient\n");
        return head;
    }
    printf("Enter the item you want to insert: ");
    scanf("%d", &item);
    temp->data = item;
    temp->next = NULL;
    if (head == NULL) 
    {
      temp->next = NULL;
      temp->prev = NULL;
    } 
    else 
    {
        struct node *ptr = head;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("One node is inserted at the end\n");
    return head;
}

struct node* deletebeg(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) 
    {
        printf("Memory insufficient\n");
        return head;
    }
    ptr = head;
    head = head->next;
    free(ptr);
    printf("One node is deleted from the beginning\n");
    return head;
}

struct node* deletelast(struct node *head) 
{
    if (head == NULL) 
    {
        printf("Memory insufficient\n");
        return head;
    }
    if (head->next == NULL) 
    {
        head = NULL;
        free(head);
    } 
    else 
    {
        struct node *ptr = head;
        struct node *ptr1;
        while (ptr->next != NULL) 
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
 
    }
    printf("One node is deleted from the end\n");
    return head;
}

void traverse(struct node *head) 
{
    struct node *ptr = head;
    if (ptr == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL)
     {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
