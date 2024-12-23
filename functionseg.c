#include<stdio.h>
int sum1(int,int);
void sum2(int,int);
int sum3();
void sum4();
void main()
{
int ch;
do{
printf("1.function with argument and return type\n");
printf("2.function with argument and no return type\n");
printf("3.function without argument and return type\n");
printf("4.function without argument and no return type\n");
printf("5.exit\n");
printf("choose an option\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("using function with argument and return type\n");
int x,y,r;
printf("enter num 1\n");
scanf("%d",&x);
printf("enter num 2\n");
scanf("%d",&y);
r=sum1(x,y);
printf("sum of %d and %d is %d\n",x,y,r);
break;
}
case 2:
{
printf("using function with argument and no return type\n");
int x,y;
printf("enter num 1\n");
scanf("%d",&x);
printf("enter num 2\n");
scanf("%d",&y);
sum2(x,y);
break;
}
case 3:
{
printf("using function without argument and return type\n");
int r;
r=sum3();
printf("sum is %d\n",r);
break;
}
case 4:
{
printf("using function without argument and no return type\n");
sum4();
break;
}
case 5:printf("exit\n");
break;
default:printf("enter valid option\n");
}
}while(ch!=5);
}
int sum1(int a,int b)
{
int sum;
sum=a+b;
return sum;
}
void sum2(int a,int b)
{
int sum;
sum=a+b;
printf("sum of %d and %d is %d\n",a,b,sum);
}
int sum3()
{
int sum,x,y;
printf("enter num 1\n");
scanf("%d",&x);
printf("enter num 2\n");
scanf("%d",&y);
sum=x+y;
return sum;
}
void sum4()
{
int sum,x,y;
printf("enter num 1\n");
scanf("%d",&x);
printf("enter num 2\n");
scanf("%d",&y);
sum=x+y;
printf("sum is %d\n",sum);;
}

