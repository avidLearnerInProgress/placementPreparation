#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;
#define INF INT_MAX

class Graph{
	int v;
	list<iPair> *adj;
	public:
	Graph(int x){
		v=x;
		adj=new list<iPair>[v];
	}
	
	void addEdge(int u,int v,int w){
		adj[u].push_back(make_pair(v,w));
		//adj[v].push_back(make_pair(u,w));
	}
	
	
	void bellmanFord(int src){
		vector<int> distance(v,INF);
		distance[src]=0;
		
		for(int j=0;j<v-1;j++){
			for(int k=0;k<v;k++){

				for(auto it=adj[k].begin();it!=adj[k].end();it++){
						
						int v=it->first;
						int w=it->second;
						
						if(distance[v]>distance[k]+w)
							distance[v]=distance[k]+w;
						
				}
			}
		}
		
		bool hasNegative=false;
		for(int k=0;k<v;k++){

				for(auto it=adj[k].begin();it!=adj[k].end();it++){
						
						int v=it->first;
						int w=it->second;
						
						if(distance[v]>distance[k]+w){
							hasNegative=true;
							k=v;
							break;
						
						}
				}
		}
		
		if(!hasNegative){
			cout << "Vertex \t\t Distance from Source\n";
			for(int i=0;i<v;i++)
				cout<<i<<"\t\t"<<distance[i]<<endl;
		}
		else cout<<"Has Negative Cycle."<<endl;
		
	}
};

int main(){
	int v= 5;
	Graph g(v);

    /* graph having no negative weight cycle*/
	g.addEdge(3, 4, 2);
	g.addEdge(4, 3, 1);
	g.addEdge(2, 4, 4);
	g.addEdge(0, 2, 5);
	g.addEdge(1, 2, -3);
	g.addEdge(0, 3, 8);
	g.addEdge(0, 1, 4);
	g.bellmanFord(0);

 // graph having negative weight cyle
/*
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 3);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 1, -6);
	g.addEdge(0, 4, 1);
	
	g.bellmanFord(0);
*/	
}


