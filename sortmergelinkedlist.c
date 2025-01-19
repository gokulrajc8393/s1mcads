#include<stdio.h>
#include<stdlib.h>

struct node 
{
int data;
struct node *next;
};

struct node* create(struct node* head);
struct node* merge(struct node* head1, struct node* head2);
void display(struct node* head);
void Sort(struct node* head);

void main() 
{
struct node *head1=NULL;
struct node *head2=NULL;
printf("Create first linked list:\n");
head1 = create(head1);
printf("Create second linked list:\n");
head2 = create(head2);

printf("\nFirst Linked List:\n");
display(head1);
printf("\nSecond Linked List:\n");
display(head2);

head1=merge(head1, head2);

printf("\nMerged Linked List:\n");
display(head1);

printf("\nsorting:\n");
Sort(head1);

printf("\nMerged Linked List(after sort):\n");
display(head1);

}


struct node* create(struct node* head)
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


struct node* merge(struct node* head1, struct node* head2) 
{
if (head1 == NULL) 
{
head1 = head2;
return head1;
}
struct node* temp = head1;

while (temp->next != NULL) {
temp = temp->next;
}
temp->next = head2;
return head1;
}


void display(struct node* head) {
struct node* temp = head;
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

void Sort(struct node* head) {
if (head == NULL) 
return;
struct node* i;
struct node* j;
int temp;

for (i = head; i != NULL; i = i->next) {
for (j = i->next; j != NULL; j = j->next) {
if (i->data > j->data) {
temp = i->data;
i->data = j->data;
j->data = temp;
}
}
}
}