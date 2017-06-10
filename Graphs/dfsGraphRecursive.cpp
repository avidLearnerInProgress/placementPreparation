#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int> *adj;
		void DFSUtil(int i,bool visited[]){
			visited[i]=true;
			cout<<i<<" ";
			
			for(auto it=adj[i].begin();it!=adj[i].end();it++)
					 if(!visited[*it])DFSUtil(*it,visited);
		}
		
	public:
		Graph(int x){
			v=x;
			adj=new list<int>[v];
		}
		
		void addEdge(int src,int dest){
			adj[src].push_back(dest);
		}

		
	 	void printGraphDFS(){
	 		bool *visited=new bool[v];
			for(int i=0;i<v;i++)
					visited[i]=false;
	 		for(int i=0;i<v;i++){
	 				if(visited[i]==false)
                        DFSUtil(i,visited);		
			 }
	 		
		 }
};



int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Depth First Traversal\n";
  	g.printGraphDFS();
	return 0;
}

