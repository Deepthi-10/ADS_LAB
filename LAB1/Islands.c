#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int count=0;
void dfs(int i,int j,int visited[][10],int a[10][10],int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m)
    return;
    if(a[i][j]==0)
    return;
    if(!visited[i][j])
    {
        visited[i][j]=1;
        dfs(i+1,j,visited,a,n,m);
        dfs(i-1,j,visited,a,n,m);
        dfs(i,j+1,visited,a,n,m);
        dfs(i,j-1,visited,a,n,m);
        dfs(i+1,j+1,visited,a,n,m);
        dfs(i-1,j-1,visited,a,n,m);
        dfs(i+1,j-1,visited,a,n,m);
        dfs(i-1,j+1,visited,a,n,m);
    }
   
}

int find_islands(int a[][10],int n,int m)
{
   
int visited[10][10];
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
     visited[i][j]=0;
 }
}

 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         if(!visited[i][j]&&a[i][j]==1){
             dfs(i,j,visited,a,n,m);
             count++;
         }
     }
 }
 return count;
 }
 void main()
{  
    int n,m,a[10][10];
    int tell;
    printf("enter number of rows and columns\n");
    scanf("%d%d",&n,&m);
    printf("enter 0's and 1's in the island matrix randomly\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    tell=find_islands(a,n,m);
    printf("number of islands:-%d",tell);
   
}
