
#include<bits/stdc++.h>
using namespace std;

#define v 9



int minDistance(int d[],bool visited[]){
	
	int min=INT_MAX,min_index;
	
	for(int i=0;i<v;i++){
		if(visited[i]==false && d[i]<=min){
			min=d[i],min_index=i;
		}
	}
	return min_index;
}



void printSolution(int b[]){
	for(int i=0;i<v;i++){
		cout<<i<<" "<<b[i]<<endl;
	}
}

void dijkstra(int graph[v][v],int src){
	
	bool visited[v];
	int d[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
		d[i]=INT_MAX;
	}
	
	d[src]=0;
	for(int i=0;i<v-1;i++){
		
		int u=minDistance(d,visited);
		visited[u]=true;
		
		for(int j=0;j<v;j++){
			
			if(visited[j]==false && graph[u][j] && d[u]!=INT_MAX && graph[u][j]+d[u]<d[j]){
				d[j]=d[u]+graph[u][j];
				
			}
		}
	}
	printSolution(d);
}


int main()
{
   
   int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
