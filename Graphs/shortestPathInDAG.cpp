#include<bits/stdc++.h>
using namespace std;
#define NINF INT_MAX

//used becz we need vertex + weight inside list declared in graph 
class AdjListNode{
	
	int v;
	int weight;
	public:
	
		AdjListNode(int _v,int _w){
			v=_v;
			weight=_w;
		}
		int getV(){return v;}
		int getWeight(){return weight;}
};

class Graph{
	int V; // number of vertices
	list<AdjListNode> *adj;
	
	void topoSortUtil(int i,bool visited[], stack<int> &s){
		visited[i]=true;
		
		list<AdjListNode>::iterator it;
		
		for(it=adj[i].begin();it!=adj[i].end();it++){
			AdjListNode node=*it;
			if(visited[node.getV()]==false){
				topoSortUtil(node.getV(),visited,s);
			}
			
		}
		s.push(i);
	}
	
	public:
	
		Graph(int x){
			V=x;
			adj=new list<AdjListNode>[V];
		}
		
		void addEdge(int u,int v,int w){
			AdjListNode node(v,w);
			adj[u].push_back(node);
		}
		
		void longestPath(int start){
			
			stack<int> s;
			bool *visited=new bool[V];
			int dist[V];
			
			for(int i=0;i<V;i++)
				visited[i]=false;
			
		
			for(int i=0;i<V;i++){
				if(visited[i]==false)topoSortUtil(i,visited,s);
			}
			
			for(int i=0;i<V;i++){
				dist[i]=NINF;
			}
			
			dist[start]=0;
			while(s.empty()==false){
				
				int u=s.top();
				s.pop();
				
				list<AdjListNode>::iterator it;
				if(dist[u]!=NINF){
					for(it=adj[u].begin();it!=adj[u].end();it++){
	
						if(dist[it->getV()] > (it->getWeight()+dist[u]))
						dist[it->getV()]=(it->getWeight()+dist[u]);
						
					}
				}
			}
			for(int i=0;i<V;i++)
				(dist[i]==NINF)?cout<<" INF " : cout<<dist[i]<<" ";
		}
		
};

int main(){
	Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    int s = 1;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    g.longestPath(s);
    return 0;
	
}
