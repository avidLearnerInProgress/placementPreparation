#include<bits/stdc++.h>
using namespace std;

class Graph{

	private:
		int v;
		list<int> *adj;
		bool

	public:
		Graph(int x){
			v=x;
			adj=new list<int>[v];
		}

		void addEdge(int src,int dest){
			adj[src].push_back(dest);
		}

		void printGraph(){
			for(int i=0;i<v;i++){
				cout<<i<<": ";
				for(auto it=adj[i].begin();it!=adj[i].end();it++)
					cout<<*it<<" ";
				cout<<endl;
			}
		}


		bool isCycleUtil(int i,bool visited[]){
			if(visited[i]==false){

				visited[i]=true;
				for(auto it=adj[i].begin();it!=adj[i].end();it++){
					if(!visited[*it])return isCycleUtil(*it,visited);
					else if(visited[*it]==true)
						return true;
				}
				return false;
			}
			return false;
		}

		bool isCycle(){
			bool *visited=new bool[v];
			for(int i=0;i<v;i++)visited[i]=false;
			for(int i=0;i<v;i++)if(isCycleUtil(i,visited))return true;
			return false;
		}
};


int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    if(g.isCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}







