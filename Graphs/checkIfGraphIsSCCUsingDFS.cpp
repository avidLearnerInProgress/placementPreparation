#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;    
    list<int> *adj;
    void fillOrder(int v, bool visited[], stack<int> &Stack);
    void DFSUtil(int v, bool visited[]);
    
	public:
	    Graph(int V);
	    void addEdge(int v, int w);
	    int isSCC();
	    Graph getTranspose();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}



void Graph::DFSUtil(int i,bool visited[]){
	visited[i]=true;
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])DFSUtil(*it,visited);
	}
	
}


void Graph::fillOrder(int i,bool visited[],stack<int> &s){
	visited[i]=true;

	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])fillOrder(*it,visited,s);
	}
	
	s.push(i);
}

Graph Graph::getTranspose(){
	
	Graph g(V);
	for(int i=0;i<V;i++){
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		g.adj[*it].push_back(i);
		}
	}
	return g;
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}


int Graph::isSCC(){
	bool *visited=new bool[V];

	for(int i=0;i<V;i++) visited[i]=false;
	DFSUtil(0,visited);
	for(int i=0;i<V;i++) if(!visited[i])return false;
		
	Graph gr=getTranspose();
	for(int i=0;i<V;i++)visited[i]=false;
	gr.DFSUtil(0,visited);
	for(int i=0;i<V;i++) if(!visited[i])return false;
	
	return true;
	
	
}

int main()
{
    // Create a graph given in the above diagram
     Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.isSCC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isSCC()? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}




