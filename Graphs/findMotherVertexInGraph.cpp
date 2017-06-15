#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;    
    list<int> *adj;
   
	public:
	    Graph(int V);
	    void addEdge(int v, int w);
	    int findMother();
	    void DFSUtil(int v, bool visited[]);
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

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

int Graph::findMother(){
	bool *visited=new bool[V];
	int v=0;
	for(int i=0;i<V;i++)visited[i]=false;
	
	
	for(int i=0;i<V;i++){
		if(!visited[i]){
			DFSUtil(i,visited);
			v=i;
		}
	}
	
	for(int i=0;i<V;i++)visited[i]=false;
	
	DFSUtil(v,visited);
	for(int i=0;i<V;i++)
		if(visited[i]==false)return -1;
	return v;	
}

int main()
{
    // Create a graph given in the above diagram
     Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.findMother();
 
    return 0;
}




