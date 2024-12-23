#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* create(struct node *head);
void search(struct node *head);
void count(struct node *head);
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
        printf("\n1.Searching\n2.Count the number of nodes\n3.Traverse\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);   
        switch (ch) 
        {
           case 1:
		   search(head);
		   break;         
           case 2:
		   count(head);
		   break;
           case 3:
		   traverse(head);
		   break;
           case 4:
           	exit(0);
           default:
           	printf("Invalid choice. Please enter 1-4\n");
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

void search(struct node *head) 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    int item, flag = 0, pos = 1;
    printf("Enter the element you want to search: ");
    scanf("%d", &item);
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == item) 
        {
            flag = 1;
            printf("Item present at position %d\n", pos);
            break;
        }
        ptr = ptr->next;
        pos++;
    }
    if (flag == 0) 
    {
        printf("Item not found\n");
    }
}

void count(struct node *head)
{
    int count = 0;
    struct node *ptr = head;
    if (ptr == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL)
     {
        count++;
        ptr = ptr->next;
    }
    printf("\nCount of nodes is %d",count);
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
