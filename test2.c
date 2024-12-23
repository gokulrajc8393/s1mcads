#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* createnode(int data)
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->data = data;
temp->next = NULL;
return temp;
}
void insertatfront(struct node** head,int data);
void insertatlast(struct node** head,int data);
void insertatpos(struct node** head,int data,int pos);
void traverse(struct node* head);
void valuesearch(struct node* head,int val);
void main()
{
int ch,data,pos,val;
struct node* head = NULL;
do
{
printf("Linked List Operations\n1.Creation\n2.Insert Node At Front\n3.Insert Node At Last\n4.Insert Node At Particular Position\n5.Traversal\n6.Searching\n7.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("enter value\n");
scanf("%d",&data);
head=createnode(data);
printf("new node created\n");
break;
}
case 2:
{
printf("enter value\n");
scanf("%d",&data);
insertatfront(&head,data);
printf("value inserted at front\n");
break;
}
case 3:
{
printf("enter value\n");
scanf("%d",&data);
insertatlast(&head,data);
printf("value inserted at last\n");
break;
}
case 4:
{
printf("enter value\n");
scanf("%d",&data);
printf("enter position\n");
scanf("%d",&pos);
insertatpos(&head,data,pos);
break;
}
case 5:
{
printf("traversing\n");
traverse(head);
break;
}
case 6:
{
printf("searching\n");
printf("enter value to search\n");
scanf("%d",&val);
valuesearch(head,val);
break;
}
case 7:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=7);
}

void insertatfront(struct node** head,int data)
{
struct node* newnode = createnode(data);
if(head==NULL)
{
newnode->next=NULL;
*head=newnode;
}
else
{
newnode->next=*head;
*head=newnode;
}
}

void insertatlast(struct node** head,int data)
{
struct node* newnode = createnode(data);
struct node *ptr;
if(head==NULL)
{
newnode->next=NULL;
*head=newnode;
}
else
{
ptr=*head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
}
ptr->next=newnode;
}

void insertatpos(struct node** head,int data,int pos)
{
struct node* newnode = createnode(data);
struct node *ptr;
int i;
if(head==NULL)
{
newnode->next=NULL;
*head=newnode;
}
else
{

if(pos==1)
{
newnode->next=*head;
*head=newnode;
printf("value inserted at position\n");
}
else
{
ptr=*head;
for(i=1;i<pos-1&&ptr!=NULL;i++)  
{  
ptr=ptr->next; 
if(ptr == NULL)  
{    
printf("\nPosition out of range\n"); 
return;  
}         
}  
newnode->next=ptr->next;  
ptr->next=newnode;  
printf("value inserted at position\n");
}
}
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

void valuesearch(struct node* head,int val)
{
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










