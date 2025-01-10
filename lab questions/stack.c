#include<stdio.h>
void push(int *);
void pop(int *);
void display(int *);
int size=10;
int top=-1;
void main()
{
int stack[20],ch;
do
{
printf("Stack Operations\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:push(stack);
break;
case 2:pop(stack);
break;
case 3:display(stack);
break;
case 4:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=4);
}

void push(int *stack)
{
int num;
if(top==size-1)
{
printf("stack overflow\n");
}
else
{
printf("enter number\n");
scanf("%d",&num);
top=top+1;
stack[top]=num;
printf("value pushed\n");
}
}

void pop(int *stack)
{
if(top<0)
{
printf("stack empty\n");
}
else
{
top=top-1;
printf("value poped\n");
}
}

void display(int *stack)
{
int i; 
if(top<0)
{
printf("stack empty\n");
}
else
{
printf("stack elements:\n");
for(i=top;i>=0;i--)
{
printf("%d",stack[i]);
printf("\n");
}
}
}




