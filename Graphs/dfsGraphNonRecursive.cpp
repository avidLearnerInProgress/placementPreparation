#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int> *adj;
		
	public:
		Graph(int x){
			v=x;
			adj=new list<int>[v];
		}
		
		void addEdge(int src,int dest){
			adj[src].push_back(dest);
		}

		
	 	void printGraphDFS(int s){
	 	    
	 		bool *visited=new bool[v];
	 		for(int i=0;i<v;i++)visited[i]=false;
	 		
            stack<int> st;
            st.push(s);
            
            while(!st.empty()){
                int s=st.top();
                st.pop();
                
                if(!visited[s]){
                    cout<<s<<" ";
                    visited[s]=true;
                }
                for(auto it=adj[s].begin();it!=adj[s].end();it++){
                    if(!visited[*it])
                        st.push(*it);
                }
            }
	 		
		 }
};



int main()
{
	 Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    cout<<"Following is Depth First Traversal\n";
  	g.printGraphDFS(0);
	return 0;
}

