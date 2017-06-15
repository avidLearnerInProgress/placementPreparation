#include<iostream>
#include <list>
using namespace std;
 
// This class represents a directed graph using adjacency list 
// representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool isReachable(int s, int d);  
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

bool Graph::isReachable(int s,int d){
	
	if(s==d)return true;
	
	bool *visited=new bool[V];
	
	for(int i=0;i<V;i++)visited[i]=false;
	
	list<int> q;
	q.push_back(s);
	visited[s]=true;
	
	while(!q.empty()){
		
		int temp=q.front();
		q.pop_front();
		
		for(auto i=adj[temp].begin();i!=adj[temp].end();i++){
			if(*i==d)return true;
			
			if(!visited[*i]){
				visited[*i]=true;
				q.push_back(*i);
			}
		}
	}
	
	return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;
}
