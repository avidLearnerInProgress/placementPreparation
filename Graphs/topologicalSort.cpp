#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int> *adj;
		
		void topoSortUtil(int i,bool visited[],stack<int> &s){
			visited[i]=true;
			for(auto it=adj[i].begin();it!=adj[i].end();it++)
					 if(!visited[*it])topoSortUtil(*it,visited,s);
					 
			s.push(i);
		}
		
	public:
		Graph(int x){
			v=x;
			adj=new list<int>[v];
		}
		
		void addEdge(int src,int dest){
			adj[src].push_back(dest);
		}

	
	 	void topologicalSort(){
	 		bool *visited=new bool[v];
	 		stack<int> s;
			for(int i=0;i<v;i++)
					visited[i]=false;
	 		for(int i=0;i<v;i++){
	 				if(visited[i]==false)
                        topoSortUtil(i,visited,s);
	 				
			 }
			 
	 		while(!s.empty()){
	 		    cout<<s.top()<<" ";
	 		    s.pop();
             }
		 }
};



int main()
{
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is Topological Sort:\n";
  	g.topologicalSort();
	return 0;
}

