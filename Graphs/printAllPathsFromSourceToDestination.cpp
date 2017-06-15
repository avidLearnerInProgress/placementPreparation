#include<bits/stdc++.h>
using namespace std;



class Graph{
    int V;
    list<int> *adj;
    public:
    
    Graph(int x){
        V=x;
        adj=new list<int>[V];
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    
    void printAllPathsUtil(int u,int d,bool visited[],int &count){
        
        visited[u]=true;
        if(u==d)
            count++;
        list<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it])
                printAllPathsUtil(*it,d,visited,count);
        }   
        visited[u]=false;
    }
    
    int printAllPaths(int s,int d){
        
        bool visited[V];
        memset(visited,false,sizeof(visited));
        int cnt=0;
        for(int i=0;i<V;i++)
            visited[i]=false;
        printAllPathsUtil(s,d,visited,cnt);
        return cnt;
    }
};

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int v,e;
            cin>>v>>e;
            Graph g(v);
            for(int i=0;i<e;i++){
                int a,b;
                cin>>a>>b;
                g.addEdge(a,b);
            }
            
            int s,d;
            cin>>s>>d;
            cout<<g.printAllPaths(s,d)<<endl;
        }
	return 0;
}
