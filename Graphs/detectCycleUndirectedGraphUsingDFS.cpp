#include<bits/stdc++.h>
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
			adj[dest].push_back(src);
		}

		void printGraph(){
			for(int i=0;i<v;i++){
				cout<<i<<": ";
				for(auto it=adj[i].begin();it!=adj[i].end();it++)
					cout<<*it<<" ";
				cout<<endl;
			}
		}


		bool isCycleUtil(int i,bool visited[],int parent){
				visited[i]=true;
				for(auto it=adj[i].begin();it!=adj[i].end();it++){
					if(!visited[*it])return isCycleUtil(*it,visited,i);
					else if(*it!=parent)
						return true;
				}
				return false;
		}

		bool isCycle(){
			bool *visited=new bool[v];
			for(int i=0;i<v;i++)visited[i]=false;
			for(int i=0;i<v;i++){
				if(!visited[i])if(isCycleUtil(i,visited,-1))return true;
			}
			
			return false;
		}
};


int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}






