#include<bits/stdc++.h>
using namespace std;
bool bfs(int rgraph[1000][1000],int s,int t,int parent[],int V){
    
    bool visited[V];
    memset(visited,0,sizeof(visited));
    
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    
    while(!q.empty()){
        
        int u=q.front();
        q.pop();
        
        for(int v=0;v<V;v++){
            
            if(!visited[v] && rgraph[u][v]>0){
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
        
    }
    
    return (visited[t]==true);
}

void dfs(int rgraph[1000][1000], int s, bool visited[],int V)
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rgraph[s][i] && !visited[i])
           dfs(rgraph, i, visited,V);
}
 

int maxflow(int graph[1000][1000],int s,int t,int V){
    
    int parent[V];
    int u,v;
    int max_flow=0;
    int rgraph[1000][1000];
    for(u=0;u<V;u++)
        for(v=0;v<V;v++)
            rgraph[u][v]=graph[u][v];
            
    while(bfs(rgraph,s,t,parent,V)){
        
        int path_flow=INT_MAX;
        
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rgraph[u][v]);
        }
         for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
       }
       
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rgraph, s, visited,V);
 
    for (int i=0;i<V;i++)
      for (int j=0;j<V;j++)
         if (visited[i] && !visited[j] && graph[i][j])
              cout<<i<<" "<<j<<" ";
             
    }   
    return 0;
}

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int V;
            cin>>V;
            int w;
            int graph[1000][1000];
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    cin>>w;
                    graph[i][j]=w;
                }
                
            }
            int s,t;
            cin>>s>>t;
            maxflow(graph,s,t,V);
            cout<<endl; 
            
        }
	return 0;
}
