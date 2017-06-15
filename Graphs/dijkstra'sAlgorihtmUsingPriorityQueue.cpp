#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<pair<int,int> > *adj;
	public:	
		Graph(int x){
			v=x;
			adj=new list<pair<int,int> >[v];
		}
		
		void addEdge(int u,int v,int w);
		void shortestPath(int s);
};


void Graph::addEdge(int u,int v,int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}


void Graph::shortestPath(int start){
	
	vector<int> dist(v,INT_MAX);
	
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	
	dist[start]=0;
	
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		
		pair<int,int> temp=pq.top();
		pq.pop();
		
		int u=temp.second;
		
		for(auto it=adj[u].begin();it!=adj[u].end();it++){
			
			int v=it->first;
			int w=it->second;
			
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
				
			}
			
		}
		
	}
	
	for(int i=0;i<v;i++){
		cout<<i<<" - "<<dist[i]<<endl;
	}
}




int main(){
	 int v = 9;
    Graph g(v);
 
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
 
    g.shortestPath(0);
 
    return 0;
	
}
