#include<stdio.h>
void addmatrix(int a[20][20],int b[20][20],int m,int n,int o,int p);
void submatrix(int a[20][20],int b[20][20],int m,int n,int o,int p);
void mulmatrix(int a[20][20],int b[20][20],int m,int n,int o,int p);
void main()
{
int a[20][20],b[20][20],i,j,m,n,o,p,ch;
printf("enter no of rows and columns of matrix 1:\n");
scanf("%d%d",&m,&n);
printf("enter matrix 1:\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("matrix 1:\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("\n");
printf("enter no of rows and columns of matrix 2:\n");
scanf("%d%d",&o,&p);
printf("enter matrix 2:\n");
for(i=0;i<o;i++)
{
for(j=0;j<p;j++)
{
scanf("%d",&b[i][j]);
}
}
printf("matrix 2:\n");
for(i=0;i<o;i++)
{
for(j=0;j<p;j++)
{
printf("%d\t",b[i][j]);
}
printf("\n");
}
printf("\n");
do
{
printf("\n1.matrix addition\n2.matrix substraction\n3.matrix multiplication\n4.exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:addmatrix(a,b,m,n,o,p);
break;
case 2:submatrix(a,b,m,n,o,p);
break;
case 3:mulmatrix(a,b,m,n,o,p);
break;
case 4:printf("exit\n");
break;
default:printf("enter correct value\n");
break;
}
}while(ch!=4);
}

void addmatrix(int a[20][20],int b[20][20],int m,int n,int o,int p)
{
int c[20][20],i,j;
if(m==o && n==p)
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
c[i][j]=a[i][j]+b[i][j];
}
}
printf("after addition:\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
else
printf("addition cannot be performed\n");
}

void submatrix(int a[20][20],int b[20][20],int m,int n,int o,int p)
{
int c[20][20],i,j;
if(m==o && n==p)
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
c[i][j]=a[i][j]-b[i][j];
}
}
printf("after substraction:\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
else
printf("substraction cannot be performed\n");
}

void mulmatrix(int a[20][20],int b[20][20],int m,int n,int o,int p)
{
int c[20][20],i,j,k;

if(n==o)
{
for(i=0;i<m;i++)
{
for(j=0;j<o;j++)
{
c[i][j]=0;
for(k=0;k<n;k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}
printf("after multiplication:\n");
for(i=0;i<m;i++)
{
for(j=0;j<p;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
}
else
printf("multiplication cannot be performed\n");
}



















