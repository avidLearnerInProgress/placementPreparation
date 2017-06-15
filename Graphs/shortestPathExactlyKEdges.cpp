#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF INT_MAX

#include <iostream>
using namespace std;
#define V 4


int shortestPath(int graph[][V],int u,int v,int k){
	
	if(k==0 && u==v)return 0;
	if(k==1 && graph[u][v]!=INF)return graph[u][v];
	if(k<0)return INF;
	
	int res=INF;
		for(int i=0;i<V;i++){
				if(graph[u][v]!=INF && u!=i && v!=i){
					int recur_res=shortestPath(graph,i,v,k-1);
					if(recur_res!=INF)
						res=min(res,graph[u][i]+recur_res);
				}
		}
		return res;
	
}


int _shortestPath(int graph[][V],int u,int v,int k){
	
		int sp[V][V][k+1];
		
		for(int e=0;e<=k;e++){
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					sp[i][j][e]=INF;
					
					if(e==0 && i==j)sp[i][j][e]=0;
					if(e==1 && graph[i][j]!=INF)sp[i][j][e]=graph[i][j];
					
					if(e>1){
						for(int t=0;t<V;t++){
							if(graph[i][t]!=INF && sp[t][j][e-1]!=INF && i!=t && j!=t)
								sp[i][j][e]=min(sp[i][j][e],graph[i][t]+sp[t][j][e-1]);
						}
						
					}
				}
			}
		}
		
		return sp[u][v][k];
}


int main(){
	int graph[V][V] = { {0, 10, 3, 2},
                        {INF, 0, INF, 7},
                        {INF, INF, 0, 6},
                        {INF, INF, INF, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << "Weight of the shortest path is " <<shortestPath(graph, u, v, k)<<endl;
    cout << "Weight of the shortest path is " <<_shortestPath(graph, u, v, k);
    return 0;
}
