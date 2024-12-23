/*to implement following operation on a single linked list
creation
deletion at start
deletion at end
deletion in b/w
04/12/24
*/
#include<stdio.h>
#include<stdlib.h>
 struct node 
{
struct node *next;
int data;

}node;

struct node* create(int n)
{ 
struct node *head=NULL;
struct node *p=NULL;
struct node *t=NULL;
int v;
for(int i=1;i<=n;i++)
{
   t=(struct node*)malloc(sizeof(struct node));
   printf("enter value to insert\n");
   scanf("%d",&v);
   t->data=v;
   t->next=NULL;
   if (head==NULL)
   {
   head=t;
   }
   else
   {
   p=head;
   while(p->next!=NULL)
   {p=p->next;
   }
   p->next=t;
   }
}
return head;
}

struct node* front(struct node *head)
{ struct node *t=NULL;
t=head;
head=head->next;
free(t);
   return head;
}
void end(struct node *head)
{ struct node *t=NULL;
struct node *p=head;
while(p->next!=NULL)
{ t=p;
p=p->next;
}
t->next=NULL;
}
void middle(struct node *head)
{ int po,v;
struct node *p=head;
struct node *t=NULL;
   printf("enter position to delete\n");
   scanf("%d",&po);
for(int i=1;i<=(po-1);i++)
{ t=p;
p=p->next;
}
t->next=p->next;

}

void display(struct node* head)
{
struct node *p=head;
while(p->next!=NULL)
{
printf("%d -> ",p->data);
p=p->next;
}
printf("%d -> ",p->data);
}
void main()
{
int n,ch;
printf("enter size \n");
scanf("%d",&n);
struct node *h=create(n);
printf("\n MENU \n 1.delete at start \n 2.delete at end \n 3.deletion at a specified position\n 4.display\n 5. exit");
printf("\n Enter your choice\n");
scanf("%d",&ch);
do 
{
switch(ch)
{
case 1 : printf("delete at start\n");h=front(h);break;
case 2: printf("delete at end\n"); end(h);break;
case 3: printf("delete in between\n");middle(h);break;
case 4:printf("elements are \n");display(h);break;
default: printf("invalid ");break;
}
printf("\n Enter your choice\n");
scanf("%d",&ch);
}while(ch!=5);
}

