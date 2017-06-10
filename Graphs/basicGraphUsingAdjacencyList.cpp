#include<bits/stdc++.h>
using namespace std;

class UnWeightedGraph{
	private:
		int v;
		list<int> *adj;
	public:
		UnWeightedGraph(int x){
			v=x;
			adj=new list<int>[v];
		}
		void addUnWeightedEdge(int src,int dest);
		void printUnWeightedGraph();
};


void UnWeightedGraph::addUnWeightedEdge(int src,int dest){

	src--,dest--;
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}

void UnWeightedGraph::printUnWeightedGraph(){

	for(int i=0;i<v;i++){
		cout<<i+1<<" ";

		for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
			cout<<"->"<<*it+1;
		}
		cout<<endl;
	}
	
	cout<<endl;
}


class WeightedGraph{
	private:
		int v;
		int w;
		vector<pair<int,int>> *adj;
	public:
		WeightedGraph(int vertices){
			v=vertices;
			adj=new vector<pair<int,int> >[v];
		}
		void addWeightedEdge(int u,int v,int w);
		void printWeightedGraph();
};

void WeightedGraph::addWeightedEdge(int src,int dest,int weight){
	adj[src].push_back(make_pair(dest,weight));
	adj[dest].push_back(make_pair(src,weight));
}

void WeightedGraph::printWeightedGraph(){
	for(int i=0;i<v;i++){
		
		cout << "Node " << i+1 << " makes an edge with \n";
		for(auto it=adj[i].begin();it!=adj[i].end();it++){
			int v=it->first;
			int w=it->second;
			cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
		}
		cout<<endl;
	}
}



int main(){
	UnWeightedGraph g(4);
	g.addUnWeightedEdge(1,2);
	g.addUnWeightedEdge(1,4);
	g.addUnWeightedEdge(2,4);
	g.addUnWeightedEdge(2,3);
	g.printUnWeightedGraph();
	WeightedGraph wg(5);

	wg.addWeightedEdge(0, 1, 10);
    wg.addWeightedEdge(0, 4, 20);
    wg.addWeightedEdge(1, 2, 30);
    wg.addWeightedEdge(1, 3, 40);
    wg.addWeightedEdge(1, 4, 50);
    wg.addWeightedEdge(2, 3, 60);
    wg.addWeightedEdge(3, 4, 70);

    wg.printWeightedGraph();
}

