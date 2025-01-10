#include<stdio.h> 
#define INF 999 
int cost[10][10],visited[10]={0,0,0,0,0,0,0,0,0,0}; 
int n,i,j,no_edges=0,total_cost=0,min,a,b; 
int main() 
{ 
printf("Enter the number of vertices : "); 
scanf("%d",&n); 
printf("Enter the cost adjacency matrix :\n"); 
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
printf("\nThe minimum cost spanning tree edges are:\n"); 
visited[1]=1; 
while (no_edges<n-1) 
{ 
min=INF;  
a=0; 
b=0; 
for(i=1;i<=n;i++) 
{ 
if(visited[i]==1) 
{ 
for (j=1;j<=n;j++) 
{ 
if (visited[j]==0 && cost[i][j]!=INF) 
{ 
if (cost[i][j]<min) 
{ 
no_edges++; 
min=cost[i][j]; a=i; 
b=j; 
}
} 
}
} 
}  
visited[b]=1; 
printf("%d-%d:%d\n",a,b,min);  
total_cost=total_cost+min; 
} 
printf("Total cost : %d\n",total_cost); 
}