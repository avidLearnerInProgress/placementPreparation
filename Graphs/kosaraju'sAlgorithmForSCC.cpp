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
	    void printSCCs();
	    Graph getTranspose();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}



void Graph::DFSUtil(int i,bool visited[]){
	visited[i]=true;
	cout<<i<<" ";
	
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


void Graph::printSCCs(){
	bool *visited=new bool[V];
	stack<int> s;
	
	
	for(int i=0;i<V;i++)visited[i]=false;
	
	
	for(int i=0;i<V;i++){
		if(!visited[i])fillOrder(i,visited,s);
	}
	
	Graph gr=getTranspose();
	
	for(int i=0;i<V;i++)visited[i]=false;
	
	while(!s.empty()){
		int u=s.top();s.pop();
		if(visited[u]==false){gr.DFSUtil(u,visited);cout<<endl;}
	}
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
 
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
 
    return 0;
}




