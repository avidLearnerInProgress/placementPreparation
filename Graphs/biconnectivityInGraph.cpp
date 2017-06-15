#include<bits/stdc++.h>
#include <climits>
#include <iomanip>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool IsBCUtil(int u,bool visited[],int parent[],int disc[],int low[]);
	
	public:	
		Graph(int x){
			V=x;
			adj=new list<int >[V];
		}
		~Graph(){delete []adj;}
		void addEdge(int u,int v);
		bool isBC();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}



bool Graph::IsBCUtil(int u,bool visited[],int parent[],int disc[],int low[]){
	
	visited[u]=true;
	static int time=0;
	int children=0;
	low[u]=disc[u]=++time;
	
	for(auto it=adj[u].begin();it!=adj[u].end();it++){
		int v=*it;
		if(!visited[v]){
			
			children++;
			parent[v]=u;
			if(IsBCUtil(v,visited,parent,disc,low))return true;
			
			low[u]=min(low[u],low[v]);
			
			if(parent[u]==-1 && children>1)return true;
			
			if(parent[u]!=-1 && low[v]>=disc[u])return true;
			
			
		}
		else if(v!=parent[u])low[u]=min(low[u],disc[v]);
	}
	
	return false;
	
}

bool Graph::isBC(){
	bool *visited=new bool[V];
	int *parent=new int[V];
	int *disc=new int[V];
	int *low=new int[V];
	
	
	for(int i=0;i<V;i++){
		visited[i]=false;
		parent[i]=-1;
	}
	
	if(IsBCUtil(0,visited,parent,disc,low)==true)	return false;
	
	for(int i=0;i<V;i++)if(!visited[i])return false;
	
	return true;

}



int main()
{
    // Create graphs given in above diagrams
    Graph g1(2);
    g1.addEdge(0, 1);
    g1.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(2, 4);
    g2.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g3(3);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g4(5);
    g4.addEdge(1, 0);
    g4.addEdge(0, 2);
    g4.addEdge(2, 1);
    g4.addEdge(0, 3);
    g4.addEdge(3, 4);
    g4.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g5(3);
    g5.addEdge(0, 1);
    g5.addEdge(1, 2);
    g5.addEdge(2, 0);
    g5.isBC()? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}
