#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int> iPair;

class Graph{
	int v;
	list<iPair> *adj;
	public:
	Graph(int x){
		v=x;
		adj=new list<iPair>[v];
		
	}
	
	void addEdge(int u,int v,int w){
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	
	
	void primMST(){
		
		priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
		vector<int> key(v,1002);
		vector<int> visited(v,false);
		vector<int> parent(v,-1);
		int src=0;
		
		pq.push(make_pair(0,src));
		key[src]=0;
		
		while(!pq.empty()){
			
			int u=pq.top().second;
			pq.pop();
			
			visited[u]=true;
			
			for(auto it=adj[u].begin();it!=adj[u].end();it++){
				int v=(*it).first;
				int weight=(*it).second;
				
				if(!visited[v] && key[v]>weight){
					key[v]=weight;
					pq.push(make_pair(key[v],v));
					parent[v]=u;
				}
			}
			
		}
		for(int i=1;i<v;i++)
				cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<endl;
				
	}
};

int main(){
	int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.primMST();
 
    return 0;
}
