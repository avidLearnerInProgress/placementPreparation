#define white 0
#define grey 1
#define black 2
/*
The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.

class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
*/
bool dfsutil(list<int> *adj,int u,int color[])
{
    color[u]=grey; 
    list<int> :: iterator it=adj[u].begin();
    for(;it!=adj[u].end();it++)
    {
        if(color[*it]==grey)
            return true;
        if(color[*it]==white && dfsutil(adj,*it,color))
            return true;
    }
    color[u]=black;
    return false;
}


/*You are required to complete this method*/
bool Graph :: isCyclic()
{
//Your code here
  //int color[V];
   int *color = new int[V];
  memset(color,0,sizeof(white));
  for(int i=0;i<V;i++)
  {
      if(color[i]==white)
      {
          if(dfsutil(adj,i,color)==true)
            return true;
      }
  }
  return false;
}
