#include<bits/stdc++.h>
using namespace std;
#define N 4
#define INF INT_MAX

/*int minimumCost(int arr[][N],int n){
	
	if(n==0)return 0;
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
		ans=min(ans,minimumCost(arr,i)+arr[i][n]);
		return ans;
}*/

int minCost(int cost[][N])
{
	int dist[N+1];
	for (int i= 0; i < N; i++)
        dist[i] = cost[0][i];
        
	for (int i = 2; i < N; i++) {
	  for (int j = 1; j < i; j++) {
		if (dist[j] + cost[j][i] < dist[i]) {
	        dist[i] = dist[j] + cost[j][i];	    
		}
	  }
	}

    for(int i = 0; i < N; i++) cout << dist[i] << " ";
	return dist[N-1];
}

int main()
{
    int cost[N][N] = { {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
    cout << "The Minimum cost to reach station "
          << N << " is " << minCost(cost);
    return 0;
}
