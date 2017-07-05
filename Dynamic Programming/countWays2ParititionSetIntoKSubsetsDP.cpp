#include<bits/stdc++.h>
using namespace std;


int countSubsets(int n,int k){
    
    int dp[n+1][k+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            
            if(i==0||j==0)dp[i][j]=0;
            else if(j==1 || j==i)dp[i][j]=1;
            else 
                dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
        }
    }
    return dp[n][k];
}


int main(){
    
    cout<<countSubsets(5,2)<<endl;
}
