#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create(struct node *head);
struct node* deletebeg(struct node *head);
struct node* deletelast(struct node *head);
struct node* deletepos(struct node *head);
void traverse(struct node *head);

void main() 
{
    struct node *head = NULL;
    int ch, ch1,item;
    printf("Creating a linked list:\n");
    head=create(head);
    while(1)
    {
        printf("\nMENU\n");
        printf("1.Delete a node from the beginning\n2.Delete a node from the end\n3.Delete a node from a specific position\n4.Traverse\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);   
        switch (ch) 
        {
           case 1:
		   head = deletebeg(head);
		   break;         
           case 2:
		   head = deletelast(head);
		   break;
           case 3:
		   head = deletepos(head);
		   break;
           case 4:
		   traverse(head);
		   break;
           case 5:
           	exit(0);
           default:
           	printf("Invalid choice. Please enter 1-5\n");
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
        first->next = temp;
        first = temp;
    }
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

struct node* deletepos(struct node *head) 
{
    int key;
    if (head == NULL) 
    {
        printf("Memory insufficient\n");
        return head;
    }
    printf("Enter the key  you want to delete: ");
    scanf("%d", &key);
    if (head->data == key) 
    {
        head = head->next;
        return head;
    }
    struct node *ptr1 = head;
    struct node *ptr = head->next;
    while (ptr != NULL)
    {
      if (ptr->data == key)
      {
        ptr1->next = ptr->next;
        free(ptr);
        printf("Node is deleted\n");
        return head;
      }
      else
      {
        ptr1 = ptr;
        ptr = ptr->next;
      }
    }
    if (ptr == NULL)
    {
      printf("Node with key does not exist\n");
    }
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
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}







