#include<bits/stdc++.h>
#include <climits>
#include <iomanip>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void apUtil(int u,bool visited[],int parent[],int disc[],int low[],bool ap[]);
	
	public:	
		Graph(int x){
			V=x;
			adj=new list<int >[V];
		}
		
		void addEdge(int u,int v);
		void articulationPoint();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::apUtil(int u,bool visited[],int parent[],int disc[],int low[],bool ap[]){
	
	visited[u]=true;
	static int time=0;
	low[u]=disc[u]=++time;
	int children=0;
	
	for(auto it=adj[u].begin();it!=adj[u].end();it++){
		int v=*it;
		if(!visited[v]){
			
			children++;
			parent[v]=u;
			apUtil(v,visited,parent,disc,low,ap);
			
			low[u]=min(low[v],low[u]);
			
			/*if(parent[u]==-1 && children>1){
				ap[u]=true;
			}
			if(parent[u]!=-1 && low[v]>=disc[u]){
				ap[u]=true;
			}*/
			if(low[v]>disc[u])cout<<u<<" - "<<v<<endl;
			
		}
		else if(v!=parent[u]){
			low[u]=min(low[u],disc[v]);
		}
		
	}
}

void Graph::articulationPoint(){
	
	bool *ap=new bool[V];
	bool *visited=new bool[V];
	int *disc=new int[V];
	int *parent=new int[V];
	int *low=new int[V];
	
	for(int i=0;i<V;i++){
		visited[i]=false;
		parent[i]=-1;
		ap[i]=false;
	}
	
	for(int i=0;i<V;i++){
		if(!visited[i])apUtil(i,visited,parent,disc,low,ap);
	}

}

int main()
{
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.articulationPoint();
 
    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.articulationPoint();
 
    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.articulationPoint();
 
    return 0;
}



