#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create(struct node *head);
struct node* insertbeg(struct node *head);
struct node* insertlast(struct node *head);
struct node* insertpos(struct node *head);
void search(struct node *head);
void traverse(struct node *head);

void main() 
{
    struct node *head = NULL;
    int ch, ch1,item;
    printf("Creating first node:\n");
    head=create(head);
    while(1)
    {
        printf("\nMENU\n");
        printf("\n1.Insert a node at beginning\n2.Insert a node at end\n3.Insert a node at a specific position\n4.Search\n5.Traverse\n6.Exit\n");
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
		   head = insertpos(head);
		   break;
           case 4:   
		   search(head);
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
   int item; 
   struct node *first=(struct node*)malloc(sizeof(struct node));
   printf("Enter the item you want to insert:");
   scanf("%d",&item);
   first->data=item;
   first->next=NULL;
   head=first;
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
    temp->next = head;
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
        head = temp;
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

struct node* insertpos(struct node *head) 
{
    int item, pos;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) 
    {
        printf("Memory insufficient\n");
        return head;
    }
    printf("Enter the item you want to insert: ");
    scanf("%d", &item);
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);
    temp->data = item;
    if (pos == 1) 
    {
        temp->next = head;
        head = temp;
        printf("Item is inserted at position 1\n");
        return head;
    }
    struct node *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) 
    {
        ptr = ptr->next;
    }
    if (ptr == NULL) 
    {
        printf("Position out of range\n");
    } 
    else 
    {
        temp->next = ptr->next;
        ptr->next = temp;
        printf("Item is inserted at position %d\n", pos);
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
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

