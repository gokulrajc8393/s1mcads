#include<stdio.h>
void enqueue(int *);
void dequeue(int *);
void display(int *);
int size=5;
int front=-1,rear=-1;
void main()
{
int queue[20],ch;
do
{
printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("\nchoose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:enqueue(queue);
break;
case 2:dequeue(queue);
break;
case 3:display(queue);
break;
case 4:printf("exit\n");
break;
default:printf("\nenter correct value\n\n");
break;
}
}while(ch!=4);
}

void enqueue(int *queue)
{
int item;
if(rear==size-1)
{
printf("\nQueue Overflow\n");
}
else 
{
printf("enter item:\n");
scanf("%d",&item);
if(front==-1 && rear==-1)
{
front=rear=0;
}
else
{
rear=rear+1;
}
queue[rear]=item;
printf("\nvalue inserted\n");
}
printf("\n");
}

void dequeue(int *queue)
{
if(front==-1 && rear==-1)
{
printf("\nQueue underflow\n");
}
else 
{
if(front==rear)
{
front=rear=-1;
}
else
{
front=front+1;
}
printf("\nvalue deleted\n");
}
printf("\n");
}

void display(int *queue)
{
int i; 
if(rear==-1)
{
printf("\nqueue empty\n");
}
else
{
printf("queue elements:\n");
for(i=front;i<=rear;i++)
{
printf("%d\t",queue[i]);
}
}
printf("\n");
}







