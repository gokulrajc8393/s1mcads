#include<stdio.h>
void insert(int *,int *);
void delete(int *,int *);
void traverse(int *,int);
void main()
{
int a[20],i,n,ch;
printf("enter limit\n");
scanf("%d",&n);
printf("enter elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("elements:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
do
{
printf("\n1.Insert an element at particular position\n2.delete an element from particular position\n3.traverse\n4.exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert(a,&n);
break;
case 2:delete(a,&n);
break;
case 3:traverse(a,n);
break;
case 4:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=4);
}

void insert(int *a,int *n)
{
int pos,j,num;
printf("enter position\n");
scanf("%d",&pos);
printf("enter element\n");
scanf("%d",&num);
if(*n==20)
printf("array overflow\n");
else
{
j=*n-1;
while(j>=pos-1)
{
a[j+1]=a[j];
j=j-1;
}
a[pos-1]=num;
*n=*n+1;
}
}

void delete(int *a,int *n)
{
int pos,j;
printf("enter position\n");
scanf("%d",&pos);
j=pos-1;
while(j<=*n-1)
{
a[j]=a[j+1];
j=j+1;
}
*n=*n-1;
}

void traverse(int *a,int n)
{
int i;
printf("elements:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
}
