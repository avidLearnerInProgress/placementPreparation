#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int> *adj;
		
	bool IDDFSUtil(int src,int target,int limit){
	    if(src==target)return true;
	    if(limit<=0)return false;
	    
	    for(auto i=adj[src].begin();i!=adj[src].end();i++){
	        if(IDDFSUtil(*i,target,limit-1)==true)return true;
        }
        
        return false;
    }
		
	public:
		Graph(int x){
			v=x;
			adj=new list<int>[v];
		}
		
		void addEdge(int src,int dest){
			adj[src].push_back(dest);
		}

	   //IDDFS: Depth Limited Search (DLS)
	 	bool IDDFS(int src,int target,int max_depth){
            for(int i=0;i<=max_depth;i++)
	 	        if(IDDFSUtil(i,target,max_depth)==true)return true;
	 	        
	 	    return false;
	 	}

};



int main()
{
	Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
 
    int target = 6, maxDepth = 3, src = 0;
    if (g.IDDFS(src, target, maxDepth) == true)
        cout << "Target is reachable from source "
                "within max depth";
    else
        cout << "Target is NOT reachable from source "
                "within max depth";
    return 0;
}

