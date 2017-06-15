#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> color;
vector<vector<int> > adj;
int maxColor;

void bfs(int node){
    
    int x,y,i;
    queue<int> q;
    q.push(node);
    visited[node]=true;
    color[node]=1;
    if(1>maxColor)maxColor=1;
    
    while(!q.empty()){
        x=q.front();
        q.pop();
        
        for(i=0;i<adj[x].size();i++){
            y=adj[x][i];
            if(x==y)continue;
            if(color[y]==-1){
                if(color[x]==1)color[y]=2;
                else color[y]=1;
                
            }
            else if(color[x]==color[y])
                color[y]++;
                
            if(color[y]>maxColor)
                maxColor=color[y];
            
            if(!visited[y]){
                visited[y]=true;
                q.push(y);
            }    
        }
    }
}

int main()
 {
	//code
        int T,N,M,E,x,y,i;
        cin>>T;
        while(T--)
        { 
            cin>>N>>M>>E;
            adj.resize(N+1);
            color.resize(N+1,-1);
            visited.resize(N+1);
            
            for(i=0;i<E;i++){
                cin>>x>>y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            
            maxColor=0;
            for(i=1;i<=N;i++){
                if(!visited[i])bfs(i);
            }
            
            if(maxColor<=M)cout<<1<<endl;
            else cout<<0<<endl;
            
            adj.clear();
            visited.clear();
            color.clear();
            
            
        }
	return 0;
}
