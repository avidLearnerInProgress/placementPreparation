#include<bits/stdc++.h>
using namespace std;

class Graph{
	
	int V;
	list<int> *adj;
	public:
	Graph(int x){
		V=x;
		adj=new list<int>[V];
	
	}
	
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bool DFSUtil(int u,vector<bool>& visited,vector<int>& vDegree,int k){
		
		visited[u]=true;
		
		for(auto it=adj[u].begin();it!=adj[u].end();it++){
			
			if(vDegree[u]<k)vDegree[*it]--;
			if(!visited[*it]){
				if(DFSUtil(*it,visited,vDegree,k))vDegree[u]--;
			}
		}
		return (vDegree[u]<k);
		
	}
	
	void printKCores(int k){
		
		vector<bool> visited(V,false);
		vector<bool> processed(V,false);
		vector<int> vDegree(V);
		int mindeg=INT_MAX;
		int startVertex;
		
		for(int i=0;i<V;i++){
			vDegree[i]=adj[i].size();
			if(vDegree[i]<mindeg)
			{
				mindeg=vDegree[i];
				startVertex=i;
			}
		}
		
		DFSUtil(startVertex, visited, vDegree, k);
		
		for(int i=0;i<V;i++)
			if(!visited[i]) 
				  DFSUtil(i, visited, vDegree, k);
	
		cout << "K-Cores : \n";
	    for (int v=0; v<V; v++)
    	{
	        if (vDegree[v] >= k)
	        {
	            cout << "\n[" << v << "]";
	            for(auto itr = adj[v].begin(); itr != adj[v].end(); ++itr)
	                if (vDegree[*itr] >= k)
	                    cout << " -> " << *itr;
	        }
    	}
    }
};

int main()
{
    // Create a graph given in the above diagram
    int k=3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);
    cout << endl << endl;
    return 0;
}
