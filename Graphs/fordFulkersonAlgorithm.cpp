#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
 
// Number of vertices in given graph
#define V 6

bool bfs(int rgraph[][V],int s,int t,int parent[]){
    
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



int maxflow(int graph[][V],int s,int t){
    
    int parent[V];
    int u,v;
    int max_flow=0;
    int rgraph[V][V];
    for(u=0;u<V;u++)
        for(v=0;v<V;v++)
            rgraph[u][v]=graph[u][v];
            
    while(bfs(rgraph,s,t,parent)) {
        
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
       
       max_flow+=path_flow;
    }   
    return max_flow;
}

int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
 
    cout << "The maximum possible flow is " << maxflow(graph, 0, 5);
 
    return 0;
}
