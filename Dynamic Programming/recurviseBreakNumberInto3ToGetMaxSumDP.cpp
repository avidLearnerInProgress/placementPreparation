#include<bits/stdc++.h>
using namespace std;


int recursiveBreak(int n){
    
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);
    }
    return dp[n];
}


int main(){
    cout<<recursiveBreak(24);
}

