#include<bits/stdc++.h>
using namespace std;

const int M=100;

void getMaxPathAverage(int cost[M][M],int N){
    int dp[N+1][N+1];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j==0)dp[i][0]=dp[i-1][0]+cost[i][0];
            else if(i==0)dp[0][j]=dp[0][j-1]+cost[0][i];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+cost[i][j];
        }
    }
    cout<<(double)dp[N-1][N-1]/(2*N-1)<<endl;
}


int main(){

    int cost[M][M] = { {1, 2, 3},
        {6, 5, 4},
        {7, 3, 9}
    };
    
     //float temp=1.123456789;
     getMaxPathAverage(cost, 3);
     //cout<<setprecision(5)<<temp<<endl;
    return 0;
}

