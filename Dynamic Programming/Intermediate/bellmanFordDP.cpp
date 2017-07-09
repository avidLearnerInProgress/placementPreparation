#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
};

bool check(vector<edge> e,int n)
{
    int dist[n];
    for(int i=0;i<n;i++)
    dist[i]=INT_MAX;
    dist[0]=0;
    int u,v,w;
    for(int j=0;j<n-1;j++)
    {
        vector<edge>::iterator i;
        for(i=e.begin();i!=e.end();i++)
        {
            edge s=*i;
            u=s.u;
            v=s.v;
            w=s.w;
            
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
            dist[v]=dist[u]+w;
        }
    }
    
        vector<edge>::iterator i;
        for(i=e.begin();i!=e.end();i++)
        {
            edge s=*i;
            u=s.u;
            v=s.v;
            w=s.w;
            
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
            return true;
        }
    
    return false;
    
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,e;
	    cin>>n>>e;
	    vector<edge> a;
	    for(int i=0;i<e;i++)
	    {
	        int u,v,w;
	        cin>>u>>v>>w;
	        edge e={u,v,w};
	        
	        a.push_back(e);
	        //cout<<e.w<<endl;
	    }
	    cout<<check(a,n)<<endl;
	    
	}
	return 0;
}
