#include<bits/stdc++.h>
using namespace std;
#define V 4

int countwalks(int graph[][V],int u,int v,int k){
	if(k==0 && u==v)return 1;
	if(k==1 && graph[u][v])return 1;
	if(k<=0)return 0;
	
	int count=0;
	for(int i=0;i<V;i++){
		if(graph[u][i]==1)count+=countwalks(graph,i,v,k-1);
	}
	return count;
}

int _countwalks(int graph[][V],int u,int v,int k){
	
	int count[V][V][k+1];
	
	for(int e=0;e<=k;e++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				
				count[i][j][e]=0;
				
				if(i==j && e==0) count[i][j][e]=1;
				
				if(e==1 && graph[i][j]) count[i][j][e]=1;
				
				if(e>1){
					for(int t=0;t<V;t++){
						
						if(graph[i][t]){
							count[i][j][e]+=count[t][j][e-1];
						}
					}
				}
			}
		}
	}
	return count[u][v][k];
}

int main()
{
    /* Let us create the graph shown in above diagram*/
     int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << countwalks(graph, u, v, k)<<endl;
    cout << _countwalks(graph, u, v, k);
    return 0;
}
