#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* enqueue(struct node* head);
struct node* dequeue(struct node* head);
void display(struct node* head);
void main()
{
int ch;
struct node* head = NULL;
do
{
printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
head=enqueue(head);
break;
}
case 2:
{
head=dequeue(head);
break;
}
case 3:
{
printf("display\n");
display(head);
break;
}
case 4:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=4);
}

struct node* enqueue(struct node* head)
{
int value;
struct node* newnode = (struct node*)malloc(sizeof(struct node));
printf("enter value to insert\n");
scanf("%d",&value);
newnode->data=value;
newnode->next=NULL;
struct node *ptr;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
}
ptr->next=newnode;
printf("value inserted\n");
return head;
}

struct node* dequeue(struct node* head)
{
if(head==NULL)
{
printf("underflow\n");
}
else
{
struct node *ptr;
ptr=head;
head=ptr->next;
free(ptr);
printf("value deleted\n");
}
return head;
}


void display(struct node* head)
{
struct node *ptr;
ptr=head;
if(head==NULL)
{
printf("stack empty\n");
}
else
{
while(ptr!=NULL)
{
printf("%d->",ptr->data);
ptr=ptr->next;
}
printf("NULL\n");
}
}












