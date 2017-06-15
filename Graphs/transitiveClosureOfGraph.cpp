#include<bits/stdc++.h>
using namespace std;

#define V 4
void print(int reach[][V]){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)
			cout<<reach[i][j]<<" ";
		cout<<endl;	
	}		
	
}
void getTransitiveClosure(int graph[][V]){
	
	int reach[V][V];
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			reach[i][j]=graph[i][j];
	
	for(int i=0;i<V;i++)
	for(int j=0;j<V;j++)		
	for(int k=0;k<V;k++)reach[i][j]=reach[i][j]||(reach[i][k]&&reach[k][j]);
	
	print(reach);
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
 
    // Print the solution
    getTransitiveClosure(graph);
    return 0;
}
