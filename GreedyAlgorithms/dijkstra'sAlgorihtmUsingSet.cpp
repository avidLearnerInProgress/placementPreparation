#include<bits/stdc++.h>
using namespace std;


class Graph {
private:
    unsigned V;
    std::list<std::pair<int, int>> *adj_list;
public:
    Graph(unsigned);
    ~Graph();
    void add_edge(int, int, int);
    void shortest_path(int);
};
 
Graph::Graph(unsigned V)
{
    this->V = V;
    adj_list = new std::list<std::pair<int, int>>[V];
}
 
Graph::~Graph()
{
    delete [] adj_list;
}
 
void Graph::add_edge(int u, int v, int w)
{
    /* a undirected graph */
    adj_list[u].push_back(std::make_pair(v, w));
    adj_list[v].push_back(std::make_pair(u, w));
}



void Graph::shortest_path(int src){
	
	set<pair<int,int>> bucket;
	
	vector<int> dist(V,INT_MAX);
	
	
	bucket.insert(make_pair(0,src));
	
	
	dist[src]=0;
	
	while(bucket.size()){
		
	pair<int,int> temp=*(bucket.begin());
		bucket.erase(bucket.begin());
		
		int u=temp.second;
		
		for(auto it=adj_list[u].begin();it!=adj_list[u].end();it++){
			
			int v=it->first;
			int w=it->second;
			
			if(dist[u]+w<dist[v]){
				
				if(dist[v]!=INT_MAX)bucket.erase(bucket.find(make_pair(dist[v],v)));
				
				dist[v]=dist[u]+w;
				bucket.insert(make_pair(dist[v],v));
				
				
			}
		}
	}
	
	for(int i=0;i<V;i++){
		cout<<i<<" - "<<dist[i]<<endl;
	}
	
	
}

int main(void)
{
    int V = 9;
    Graph g(V);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    g.shortest_path(0);
    return 0;
}


/*http://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
*/
 
