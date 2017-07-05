//Maximum path sum that starting with any cell of 0-th row and ending with any cell of (N-1)-th row

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 4

void maxSum(int mat[][N]){
    
    int dp[N][N];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++)dp[0][i]=mat[0][i];
    
    
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            
            if(j==0){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+mat[i][j];
            }
            
            else if(j==N-1){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+mat[i][j];
            }
            
            else 
                dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+mat[i][j];
        }
    }
    
    int res=0;
    for(int i=0;i<N;i++)
        res=max(res,dp[N-1][i]);
    
    cout<<res<<endl;    
}


int main(){
     int Mat[4][4] = { { 4, 2 , 3 , 4 },
        { 2 , 9 , 1 , 10},
        { 15, 1 , 3 , 0 },
        { 16 ,92, 41, 44 }
    };
 
    maxSum(Mat);
	return 0;
}
