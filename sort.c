#include<stdio.h>
void main()
{
int a[30],i,n,j,temp;
printf("enter limit:\n");
scanf("%d",&n);
printf("enter elements:\n");
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
}
