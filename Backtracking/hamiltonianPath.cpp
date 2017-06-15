#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool isHamiltonianPath(int node,int count,int N)
{
    int i,x;
    bool pathExists;
    if(count==N)
      return true;
    visited[node] = true;
    pathExists = false;
    for(i=0;i<adj[node].size();i++)
    {
        x = adj[node][i];
        if(!visited[x])
        {
            pathExists = isHamiltonianPath(x,count+1,N);
            if(pathExists)  
              return true;
        }
    }
    visited[node] = false;
    return false;
}

int main() 
{
    int t,T,N,M,i,x,y;
    bool pathExists;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>N>>M;
        adj.resize(N+1);
        visited.resize(N+1);
        for(i=1;i<=M;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        pathExists = false;
        for(i=1;i<=N;i++)
        {
            pathExists = isHamiltonianPath(i,1,N);
            if(pathExists)
              break;
        }
        cout<<pathExists<<"\n";
        adj.clear();
        visited.clear();
    }
    
	
	return 0;
}
