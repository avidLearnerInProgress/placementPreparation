#include<bits/stdc++.h>
using namespace std;


int jumps(int arr[],int n){
    
    
    if(n==0 || arr[0]==0)return -1;
    
    int dp[n];
    
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<i;j++){
            if(i<=j+arr[j] && dp[j]!=INT_MAX){
                dp[i]=min(dp[i],dp[j]+1);
                break;
            }
            
        }
    }
    return dp[n-1];
}

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int n;cin>>n;
            int arr[n];
            for(int i=0;i<n;i++)cin>>arr[i];
            
            cout<<jumps(arr,n)<<endl;
        }
	return 0;
}
