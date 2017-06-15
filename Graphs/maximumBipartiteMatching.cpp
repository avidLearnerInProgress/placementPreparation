#include <iostream>
#include <string.h>
using namespace std;
 
// M is number of applicants and N is number of jobs
#define M 6
#define N 6

bool bpm(bool graph[M][N],int u,int matchR[],bool seen[]){
	
	for(int v=0;v<N;v++){
		
		if(graph[u][v] && !seen[v]){
			
			seen[v]=true;
			
			if(matchR[v] || bpm(graph,matchR[v],matchR,seen)){
				matchR[v]=u;
				return true;
			}
		}
	}
	
	return false;
}

int maxBipartiteMatching(bool graph[M][N]){
	
	int matchR[N];
	memset(matchR,-1,sizeof(matchR));
	int result=0;
	for(int i=0;i<M;i++){
		bool seen[N];
		memset(seen,0,sizeof(seen));
		
		if(bpm(graph,i,matchR,seen))result++;
		
	}
	
	return result;
}

int main()
{
    // Let us create a bpGraph shown in the above example
    bool bpGraph[M][N] = {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };
 
    cout << "Maximum number of applicants that can get job is "
         << maxBipartiteMatching(bpGraph);
 
    return 0;
}
