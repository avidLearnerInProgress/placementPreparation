#include<bits/stdc++.h>
using namespace std;


#define v 4
#define INF 9999

void printSolution(int res[][v]){
	
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(res[i][j]==INF)cout<<"INF"<<" ";
			else cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}


void printFloyd(int graph[][v]){
	
	int res[v][v];
	
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			res[i][j]=graph[i][j];
	
	
	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				if(res[i][j]>res[i][k]+res[k][j])
					res[i][j]=res[i][k]+res[k][j];
			}
		}
	}
	printSolution(res);
}

int main()
{
    int graph[v][v] = { 
    					{0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    printFloyd(graph);
    return 0;
}
