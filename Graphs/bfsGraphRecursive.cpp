#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int v;
		list<int> *adj;
		void BFSUtil(bool visited[],queue<int> &q){
		    if(q.empty())return;
		    
		    int v=q.front();
		    q.pop();
		    cout<<v<<" ";
		    
            for(int i:adj[v]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
		    BFSUtil(visited,q);
        }
	public:
		Graph(int x){
			v=x;
			adj=new list<int>[v];
		}
		
		void addEdge(int src,int dest){
			adj[src].push_back(dest);
		}

		void printGraphBFS(int s){

			bool *visited=new bool[v];
			for(int i=0;i<v;i++)visited[i]=false;
			
            queue<int> q;
            visited[s]=true;
            q.push(s);
            BFSUtil(visited,q);
                
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
    cout << "Following is Breadth First Traversal "<<endl;
    g.printGraphBFS(2);
    cout<<endl;
    g.printGraphBFS(1);
	return 0;
}

