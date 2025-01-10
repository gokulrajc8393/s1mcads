#include<stdio.h>
void lsearch(int *,int);
void bsearch(int *,int);
void main()
{
int a[30],i,n,ch;
printf("enter limit of array:\n");
scanf("%d",&n);
printf("enter array elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);	
}
printf("array elements:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
do
{
printf("\n1.using linear search\n2.using binary search\n3.exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:lsearch(a,n);
break;
case 2:bsearch(a,n);
break;
case 3:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=3);
}

void lsearch(int *a,int n)
{
int i,f=0,num;
printf("enter element to search:\n");
scanf("%d",&num);
for(i=0;i<n;i++)
{
if(num==a[i])
{
f=1;
break;
}
}
if(f==1)
printf("element %d found at position %d\n",num,i+1);
else
printf("element not found\n");
}

void bsearch(int *a,int n)
{
int pos,ub,lb,mid,num,i,j,temp;
printf("enter element to search:\n");
scanf("%d",&num);
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("sorted array:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
printf("\n");
pos=-1;
lb=0;
ub=n-1;
while(lb<=ub)
{
mid=(lb+ub)/2;
if(num==a[mid])
{
pos=mid;
break;
}
else if(num<a[mid])
{
ub=mid-1;
}
else
{
lb=mid+1;
}
}
if(pos==-1)
printf("element not found\n");
else
printf("element %d found at position %d\n",num,pos+1);
}


