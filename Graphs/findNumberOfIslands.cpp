#include<bits/stdc++.h>
using namespace std;

int  M[1000][1000],row,col;
int visited[1000][1000];     

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

bool canGoThere(int x,int y){
    return(x<row && y<col && !visited[x][y] && M[x][y]==1);
}

void dfs(int x,int y,int col){
    visited[x][y]=col;
    for(int i=0;i<8;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(canGoThere(xx,yy))dfs(xx,yy,col);
    }
    
}

int main(){
    
    int color=0;
    cin>>row>>col;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>M[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!visited[i][j] && M[i][j]==1)dfs(i,j,++color);
        }
    }
    cout<<"Number of Islands or connected components are: "<<color<<endl;
	return 0;
}






/* Alternative Solution:

int m,n;
bool vis[MAX][MAX];
bool safe(int a[][MAX],bool vis[][MAX],int i,int j)
{
    return ((i>=0) && (i<n) && (j>=0) && (j<m) && a[i][j] && !vis[i][j]);
}
void dfs(int a[][MAX],bool vis[][MAX],int i,int j)
{
    vis[i][j]=true;
    if(safe(a,vis,i+1,j))
    {
        dfs(a,vis,i+1,j);
    }
    if(safe(a,vis,i+1,j+1))
    {
        dfs(a,vis,i+1,j+1);
    }
    if(safe(a,vis,i,j+1))
    {
        dfs(a,vis,i,j+1);
    }
    if(safe(a,vis,i-1,j+1))
    {
        dfs(a,vis,i-1,j+1);
    }
    if(safe(a,vis,i-1,j))
    {
        dfs(a,vis,i-1,j);
    }
    if(safe(a,vis,i-1,j-1))
    {
        dfs(a,vis,i-1,j-1);
    }
    if(safe(a,vis,i,j-1))
    {
        dfs(a,vis,i,j-1);
    }
    if(safe(a,vis,i+1,j-1))
    {
        dfs(a,vis,i+1,j-1);
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    m=M;
    n=N;
    memset(vis,false,sizeof vis);
    int x=0;
    
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(A[i][j] && !vis[i][j])
        {
            dfs(A,vis,i,j);
            x++;
        }
    }
}
return x;
}
*/
