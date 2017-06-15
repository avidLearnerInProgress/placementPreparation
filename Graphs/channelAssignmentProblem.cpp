#include <iostream>
#include <string.h>
#include <vector>
#define M 3
#define N 4
using namespace std;

// see comment to check the difference from maxBipartiteMatching problem...

bool bpm(int graph[M][N],int u,int matchR[],bool seen[]){
	
	for(int v=0;v<N;v++){
		
		if(graph[u][v]>0 && !seen[v]){
			
			seen[v]=true;
			
			if(matchR[v]<0 || bpm(graph,matchR[v],matchR,seen)){   //difference 
				matchR[v]=u;
				return true;
			}
		}
	}
	
	return false;
}

void maxBipartiteMatching(int graph[M][N]){
	
	int matchR[N];
	memset(matchR,-1,sizeof(matchR));
	int result=0;
	for(int i=0;i<M;i++){
		bool seen[N];
		memset(seen,0,sizeof(seen));
		
		if(bpm(graph,i,matchR,seen))result++;
		
	}
	
	cout << "The number of maximum packets sent in the time slot is "
         << result << "\n";
    for (int x=0; x<N; x++)
        if (matchR[x]+1!=0)
            cout << "T" << matchR[x]+1 << "-> R" << x+1 << "\n";

}



int main()
{
    int table[M][N] = {{0, 2, 0}, {3, 0, 1}, {2, 4, 0}};
   maxBipartiteMatching(table);
    return 0;
}
