#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node* createnode(struct node* head)
{
struct node *p;
int value,n;
printf("enter size \n");
scanf("%d",&n);
if(n <= 0) {
printf("List size must be greater than 0.\n");
return 0;
}
for(int i=1;i<=n;i++)
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
printf("enter value to insert\n");
scanf("%d",&value);
temp->data=value;
temp->prev=NULL;
temp->next=NULL;
if (head==NULL)
{
head=temp;
}
else
{
p=head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
temp->prev=p;
}
}
return head;
}

struct node* insertatfront(struct node* head);
struct node* insertatlast(struct node* head);
struct node* deleteatfront(struct node* head);
struct node* deleteatlast(struct node* head);
void traverse(struct node* head);
void noofnodes(struct node* head);
void main()
{
int ch,data;
struct node *head=NULL;
printf("Creating a linked list:\n");
head=createnode(head);
do
{
printf("Linked List Operations\n1.Insert Node At Front\n2.Insert Node At Last\n3.Delete Node At Front\n4.Delete Node At Last\n5.Traversal\n6.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
head=insertatfront(head);
printf("value inserted at front\n");
break;
}
case 2:
{
head=insertatlast(head);
printf("value inserted at last\n");
break;
}
case 3:
{
head=deleteatfront(head);
printf("value deleted from front\n");
break;
}
case 4:
{
head=deleteatlast(head);
printf("value deleted from last\n");
break;
}
case 5:
{
printf("traversing\n");
traverse(head);
break;
}
case 6:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=6);
}

struct node* insertatfront(struct node* head)
{
int value;
struct node* newnode = (struct node*)malloc(sizeof(struct node));
printf("enter value to insert\n");
scanf("%d",&value);
newnode->data=value;
newnode->prev=NULL;
newnode->next=NULL;
if(head==NULL)
{
newnode->next=NULL;
newnode->prev=NULL;
head=newnode;
}
else
{
newnode->next=head;
newnode->prev=NULL;
head=newnode;
}
return head;
}

struct node* insertatlast(struct node* head)
{
int value;
struct node* newnode = (struct node*)malloc(sizeof(struct node));
printf("enter value to insert\n");
scanf("%d",&value);
newnode->data=value;
newnode->prev=NULL;
newnode->next=NULL;
struct node *ptr;
if(head==NULL)
{
newnode->next=NULL;
newnode->prev=NULL;
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
newnode->prev=ptr;
return head;
}

struct node* deleteatfront(struct node* head)
{
if(head==NULL)
{
printf("linked list underflow\n");
}
else
{
struct node *ptr;
ptr=head;
head=ptr->next;
head->prev=NULL;
free(ptr);
}
return head;
}

struct node* deleteatlast(struct node* head)
{
if(head==NULL)
{
printf("linked list underflow\n");
}
else
{
if(head->next==NULL)
{
head=NULL;
free(head);
}
else
{
struct node *ptr;
struct node *ptr1;
ptr=head;
while(ptr->next!=NULL)
{
ptr1=ptr;
ptr=ptr->next;
}
ptr1->next=NULL;
ptr->prev=NULL;
free(ptr);
}
}
return head;
}

void traverse(struct node* head)
{
struct node *ptr;
ptr=head;
if(head==NULL)
{
printf("list empty\n");
}
else
{
while(ptr!=NULL)
{
printf("%d<->",ptr->data);
ptr=ptr->next;
}
printf("NULL\n");
}
}










