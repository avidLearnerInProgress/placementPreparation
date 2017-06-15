#include<bits/stdc++.h>
using namespace std;

class Graph
{
  int V;    // No. of vertices
  list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
  Graph(int V)  { this->V = V;  adj = new list<int>[V];  }
  ~Graph()      { delete [] adj;  }
 
  // functions to add and remove edge
  void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); }
  void rmvEdge(int u, int v);
 
  // Methods to print Eulerian tour
  void printEulerTour();
  void printEulerUtil(int s);
 
  // This function returns count of vertices reachable from v. It does DFS
  int DFSCount(int v, bool visited[]);
 
  // Utility function to check if edge u-v is a valid next edge in
  // Eulerian trail or circuit
  bool isValidNextEdge(int u, int v);
};


void Graph::printEulerTour(){
	int u=0;
	for(int i=0;i<V;i++){
		if(adj[i].size() & 1){
			u=i;break;
		}
	}
	printEulerUtil(u);
	cout<<endl;

}

void Graph::printEulerUtil(int u){
	for(auto it=adj[u].begin();it!=adj[u].end();it++){
		int v=*it;
		if(v!=-1 && isValidNextEdge(u,v)){

			cout<<u<<" - "<<v<<"\t";
			rmvEdge(u,v);
			printEulerUtil(v);
		}
	}
}

bool Graph::isValidNextEdge(int u,int v){
	int count=0;
	for(auto it=adj[u].begin();it!=adj[u].end();it++){
		if(*it!=-1)count++;


	}
	if(count==1)return true;
	bool visited[V];
	memset(visited,false,V);
	int count1=DFSCount(u,visited);
	rmvEdge(u,v);
	memset(visited,false,V);
	int count2=DFSCount(u,visited);
	addEdge(u,v);

	return (count1>count2)?false:true;
}


void Graph::rmvEdge(int u,int v){
	auto iv=find(adj[u].begin(),adj[u].end(),v);
	*iv=-1;

	auto iu=find(adj[v].begin(),adj[v].end(),u);
	*iu=-1;
}


int Graph::DFSCount(int v,bool visited[]){
	visited[v]=true;
	int count=1;

	for(auto it=adj[v].begin();it!=adj[v].end();it++){
	if(*it != -1 && !visited[*it])
		count+=DFSCount(*it,visited);
	}
	return count;
}

int main()
{
  // Let us first create and test graphs shown in above figure
  Graph g1(4);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 2);
  g1.addEdge(2, 3);
  g1.printEulerTour();
 
  Graph g2(3);
  g2.addEdge(0, 1);
  g2.addEdge(1, 2);
  g2.addEdge(2, 0);
  g2.printEulerTour();
 
  Graph g3(5);
  g3.addEdge(1, 0);
  g3.addEdge(0, 2);
  g3.addEdge(2, 1);
  g3.addEdge(0, 3);
  g3.addEdge(3, 4);
  g3.addEdge(3, 2);
  g3.addEdge(3, 1);
  g3.addEdge(2, 4);
  g3.printEulerTour();
 
  return 0;
}
