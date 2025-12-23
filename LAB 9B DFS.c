#include<stdio.h>
#define max 10

int graph[max][max];
int visited[max];
int n;

void dfs(int v)
{
    int i;
  visited[v]=1;
  for(i=0;i<n;i++)
  {
   if(graph[v][i]==1 && !visited[i])
   {
    dfs(i);
}


int mian()
{
int i,j,start=0;
printf("Enter no of vertices:");
scanf("%d",&n);
printf("Enter the adjecency matrix:");
for (i=0;i<n;i++)
{
for(j=0;j<i;j++)
    {

        scanf("%d",&graph[i][j]);
    }
}
for(i=0;i<n;i++)
{

    visited[i]=0;
}
dfs(start);
for(i=0;i<n;i++)
{
    if(!visited[i])
    {
        printf("The graph is not connected");
        return 0;
    }
}
printf("The graph is connected");
return 0;
}
