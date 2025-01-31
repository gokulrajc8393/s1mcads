#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
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
}
}
return head;
}
struct node* deleteatfront(struct node* head);
struct node* deleteatlast(struct node* head);
struct node* deleteatpos(struct node* head);
void traverse(struct node* head);
void main()
{
int ch,data,pos,val;
struct node *head=NULL;
printf("Creating a linked list:\n");
head=createnode(head);
do
{
printf("Linked List Operations\n1.Delete From Front\n2.Delete From Last\n3.Delete From Particular Position\n4.Traversal\n5.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
head=deleteatfront(head);
printf("value deleted from front\n");
break;
}
case 2:
{
head=deleteatlast(head);
printf("value deleted from last\n");
break;
}
case 3:
{
head=deleteatpos(head);
break;
}
case 4:
{
printf("traversing\n");
traverse(head);
break;
}
case 5:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=5);
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
free(ptr);
}
}
return head;
}

struct node* deleteatpos(struct node* head)
{
struct node *ptr;
struct node *ptr1;
int i,pos;    
printf("enter position\n");
scanf("%d",&pos);
if (head == NULL)
{
printf("Linked list underflow\n");
return head;
}
if (pos==1)
{
ptr=head;
head=ptr->next;
free(ptr);
printf("Value deleted from position\n");
}
else
{
ptr = head;
for(i=1;i<pos-1&&ptr!=NULL;i++)  
{  
ptr = ptr->next; 
}
if (ptr==NULL||ptr->next==NULL)
{
printf("Position out of range\n");
return head;
}
ptr1 = ptr->next;
ptr->next = ptr1->next;
free(ptr1);
printf("Value deleted from position\n");
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
printf("%d->",ptr->data);
ptr=ptr->next;
}
printf("NULL\n");
}
}










