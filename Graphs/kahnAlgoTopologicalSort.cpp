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

	
	 	void topologicalSort(){
	 	    
	 	    vector<int> in_degree(v,0);
	 	    
	 	    
	 	    for(int i=0;i<v;i++){
	 	        
                for(list<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
                        in_degree[*it]++;
	 	         }
            }
            queue<int> q;
            for(int i=0;i<v;i++)
                if(in_degree[i]==0)
                    q.push(i);
            
            int count=0;
            vector<int> result;
            
            while(!q.empty()){
                int u=q.front();
                q.pop();
                result.push_back(u);
                
                for(list<int>::iterator itr=adj[u].begin();itr!=adj[u].end();itr++){
                    if(--in_degree[*itr]==0)
                        q.push(*itr);
                }
                count++;
                
            }
            
            if(count!=v)cout<<"Circular Graph."<<endl;
            for(int i=0;i<result.size();i++)
                cout<<result[i]<<" ";
            cout<<endl;
  
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

