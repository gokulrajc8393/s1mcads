#include<stdio.h>
void enqueue(int *);
void dequeue(int *);
void display(int *);
int size=5;
int front=-1,rear=-1,count=0;
void main()
{
int queue[20],ch;
do
{
printf("Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("choose an operation:\n");
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
default:printf("enter correct value\n\n");
break;
}
}while(ch!=4);
}

void enqueue(int *queue)
{
int item;
if(count==size)
{
printf("Queue Overflow\n");
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
if(front==-1&&rear==-1) 
{
front=rear=0;
} 
else 
{
rear=(rear+1)%size;
}
queue[rear] = item;
count=count+1;
printf("Value inserted\n");
}
printf("\n");
}

void dequeue(int *queue)
{
if(count==0)
{
printf("Queue underflow\n");
}
else 
{
if(front==rear)
{
front=rear=-1;
}
else
{
front=(front+1)%size;
}
count=count-1;
printf("value deleted\n");
}
printf("\n");
}

void display(int *queue)
{
int i; 
if(count==0)
{
printf("queue empty\n");
}
else
{
printf("queue elements:\n");
int i=front;
while(i!=rear) 
{
printf("%d\t", queue[i]);
i = (i+1) % size;
}
printf("%d\n", queue[rear]);
}
printf("\n");
}







