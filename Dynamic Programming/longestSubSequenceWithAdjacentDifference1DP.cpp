#include <bits/stdc++.h>
using namespace std;

int longestSubSeqWithAdj1(int arr[],int n){
    
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=1;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]+1 || arr[i]==arr[j]-1)dp[i]=max(dp[i],dp[j]+1);
        }
    }
    
    cout<<*max_element(dp,dp+n)<<endl;
    return 0;
}

int main() {
	//code
	int arr[] = {1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    longestSubSeqWithAdj1(arr, n);
	return 0;
}
