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
struct node* insertatfront(struct node* head);
struct node* insertatlast(struct node* head);
struct node* insertafterkey(struct node* head);
void traverse(struct node* head);
void valuesearch(struct node* head);
void main()
{
int ch,data,pos,val;
struct node* head = NULL;
printf("Creating a linked list:\n");
head=createnode(head);
do
{
printf("Linked List Operations\n1.Insert Node At Front\n2.Insert After Particular Node\n3.Insert Node At Last\n4.Searching\n5.Traversal\n6.Exit\n");
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
head=insertafterkey(head);
break;
}
case 3:
{
head=insertatlast(head);
printf("value inserted at last\n");
break;
}
case 4:
{
printf("searching\n");
valuesearch(head);
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
newnode->next=NULL;
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
return head;
}

struct node* insertatlast(struct node* head)
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
return head;
}

struct node* insertafterkey(struct node* head)
{
int value,key;
struct node* newnode = (struct node*)malloc(sizeof(struct node));
printf("enter value to insert\n");
scanf("%d",&value);
newnode->data=value;
newnode->next=NULL;
printf("enter key\n");
scanf("%d",&key);
struct node *ptr;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
ptr=head;
while (ptr != NULL)
{
if (ptr->data == key)
{
newnode->next=ptr->next; 
ptr->next=newnode;
printf("Node inserted after key\n");
return head;
}
else
{
ptr = ptr->next;
}
}
if (ptr == NULL)
{
printf("Node with key does not exist\n");
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
printf("%d->",ptr->data);
ptr=ptr->next;
}
printf("NULL\n");
}
}

void valuesearch(struct node* head)
{
int val;
printf("enter value to search\n");
scanf("%d",&val);
struct node *ptr;
ptr=head;
int flag=0,pos=1;
while(ptr!=NULL)
{
if(ptr->data==val)
{
flag=1;
printf("Item Present at position %d\n",pos);
break;
}
else
{
ptr=ptr->next;
pos=pos+1;
}
}
if(flag==0)
{
printf("Item Not Found\n");
}
}










