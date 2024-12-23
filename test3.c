#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* createnode(int n)
{
struct node* head;
struct node *p;
int value;
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
void deleteatfront(struct node** head);
/*void deleteatlast(struct node** head);
void deleteatpos(struct node** head,int pos);*/
void traverse(struct node* head);
void main()
{
int n,ch,data,pos,val;
printf("enter size \n");
scanf("%d",&n);
struct node *new=createnode(n);
do
{
printf("Linked List Operations\n1.Delete From Front\n2.Delete From Last\n3.Delete From Particular Position\n4.Traversal\n5.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
deleteatfront(&new);
printf("value deleted from front\n");
break;
}
/*case 2:
{
deleteatlast(&head);
printf("value deleted from last\n");
break;
}
case 3:
{
printf("enter position\n");
scanf("%d",&pos);
deleteatpos(&head,pos);
break;
}*/
case 4:
{
printf("traversing\n");
traverse(new);
break;
}
case 5:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=5);
}

void deleteatfront(struct node** head)
{
if(head==NULL)
{
printf("linked list underflow\n");
}
else
{
struct node *ptr;
ptr=*head;
*head=ptr->next;
free(ptr);
}
}
/*
void insertatlast(struct node** head,int data)
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

}
}
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
*/
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










