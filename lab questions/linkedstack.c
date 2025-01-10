#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* push(struct node* head);
struct node* pop(struct node* head);
void display(struct node* head);
void main()
{
int ch;
struct node* head = NULL;
do
{
printf("Stack Operations\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
head=push(head);
break;
}
case 2:
{
head=pop(head);
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

struct node* push(struct node* head)
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
newnode->next=head;
head=newnode;
}
printf("value pushed\n");
return head;
}

struct node* pop(struct node* head)
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
printf("value poped\n");
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












