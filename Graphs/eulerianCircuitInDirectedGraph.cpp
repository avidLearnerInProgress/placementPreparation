#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;    
    list<int> *adj;
    int *in;
    
    void DFSUtil(int v, bool visited[]);
	public:
	    Graph(int V);
	    void addEdge(int v, int w);
	    void printSCCs();
	    Graph getTranspose();
	    bool isEulerianCycle();
	    bool isSC();
	    
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for(int i=0;i<V;i++)in[i]=0;
}



void Graph::DFSUtil(int i,bool visited[]){
	visited[i]=true;
	cout<<i<<" ";
	
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it])DFSUtil(*it,visited);
	}
	
}

bool Graph::isEulerianCycle()
{
    // Check if all non-zero degree vertices are connected
    if (isSC() == false)
        return false;
 
    // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < V; i++)
        if (adj[i].size() != in[i])
            return false;
 
    return true;
}


Graph Graph::getTranspose(){
	
	Graph g(V);
	for(int i=0;i<V;i++){
	for(auto it=adj[i].begin();it!=adj[i].end();it++){
		g.adj[*it].push_back(i);
		 (g.in[*it])++;
		}
	}
	return g;
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);(in[w])++;
}


bool Graph::isSC(){
	bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    int n;
    for (n = 0; n < V; n++)
        if (adj[n].size() > 0)
          break;
    DFSUtil(n, visited);
    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
              return false;
    Graph gr = getTranspose();
 
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    gr.DFSUtil(n, visited);
    for (int i = 0; i < V; i++)
        if (adj[i].size() > 0 && visited[i] == false)
             return false;
 
    return true;
}

int main()
{
    // Create a graph given in the above diagram

    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
 
    if (g.isEulerianCycle())
       cout << "Given directed graph is eulerian \n";
    else
       cout << "Given directed graph is NOT eulerian \n";
    return 0;

}




