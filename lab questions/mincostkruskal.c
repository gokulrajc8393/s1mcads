#include<stdio.h>  
#define INF 999 
int cost[10][10],visited[10]={0,0,0,0,0,0,0,0,0,0},parent[10];  
int n,i,j,no_edges=0,total_cost=0,min,a,b,u,v; 
int find(int);  
int uni(int,int);  
int main() 
{ 
printf("Enter the no. of vertices : ");  
scanf("%d",&n); 
printf("Enter the adjacency matrix : \n");  
for(int i=1;i<=n;i++) 
{ 
for(int j=1;j<=n;j++) 
{ 
scanf("%d",&cost[i][j]); 
if (cost[i][j]==0) 
{ 
cost[i][j]=INF; 
}
}
} 
printf("\nCost of edges\n");  
visited[1]=1; 
while (no_edges<n-1) 
{ 
min=INF;  
a=0; 
b=0; 
for(i=1;i<=n;i++) 
{ 
for (j=1;j<=n;j++) 
{ 
if (cost[i][j]<min) 
{ 
min=cost[i][j];  
a=u=i; 
b=v=j; 
}
}
} 
u=find(u);  
v=find(v);  
if(uni(u,v)) 
{ 
printf("%d-%d:%d\n",a,b,min);  
no_edges++;  
total_cost=total_cost+min; 
} 
cost[a][b]=cost[b][a]=INF; 
} 
printf("Total cost : %d\n",total_cost); 
} 
int find(int i) 
{ 
while(parent[i])  
i=parent[i]; 
return i; 
} 
int uni(int i,int j) 
{ 
if(i!=j) 
{ 
parent[j]=i;  
return 1; 
} 
return 0; 
} 