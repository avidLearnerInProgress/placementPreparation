#include<bits/stdc++.h>
#include <climits>
#include <iomanip>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void SCCUtil(int u,int disc[],int low[],bool stackMember[],stack<int> *s);
	
	public:	
		Graph(int x){
			V=x;
			adj=new list<int >[V];
		}
		
		void addEdge(int u,int v);
		void printSCC();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::SCCUtil(int u,int disc[],int low[],bool stackMember[],stack<int> *s){
	
	static int time=0;
	disc[u]=low[u]=++time;
	s->push(u);
	stackMember[u]=true;
	
	for(auto it=adj[u].begin();it!=adj[u].end();it++){
		
		int v=*it;
		
		if(disc[v]==-1){
			SCCUtil(v,disc,low,stackMember,s);
			low[u]=min(low[u],low[v]);
		}
		else if(stackMember[v] == true)
            low[u]=min(low[u], disc[v]);
            
	}
	int w=0;
    if (low[u]==disc[u])
    {
        while (s->top()!=u)
        {
            w=(int)s->top();
            cout<<w<<" ";
            stackMember[w]=false;
            s->pop();
        }
        	w=(int)s->top();
            cout<<w<<" ";
            stackMember[w]=false;
            s->pop();
    }
	
}

void Graph::printSCC(){
	
	stack<int> *st=new stack<int>();
	int *disc=new int[V];
	int *low=new int[V];
	bool *stackMember=new bool[V];
	
	for(int i=0;i<V;i++){
		stackMember[i]=false;
		disc[i]=-1;
		low[i]=-1;
	}
	
	for(int i=0;i<V;i++){
		if(disc[i]==-1)SCCUtil(i,disc,low,stackMember,st);
	}
}

int main()
{
    cout << "\nSCCs in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.printSCC();
 
    cout << "\nSCCs in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.printSCC();
 
    cout << "\nSCCs in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.printSCC();
 
    cout << "\nSCCs in fourth graph \n";
    Graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    g4.printSCC();
 
    cout << "\nSCCs in fifth graph \n";
    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);
    g5.printSCC();
 
    return 0;
}


