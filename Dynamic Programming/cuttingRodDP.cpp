#include<bits/stdc++.h>
using namespace std;

int rodCut(int arr[],int n){
    
     int dp[n+1];
            dp[0]=0;
            
            for(int i=1;i<=n;i++){
                int _max=INT_MIN;
                for(int j=0;j<i;j++){   
                    //max of(upper row index + (j-i)th index , current sum ) 
                    //Courtesy Tushar Roy :p
                    _max=max(_max,arr[j]+dp[i-j-1]);
                }
                dp[i]=_max;
            }
            cout<<dp[n]<<endl;
    return 0;
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
            rodCut(arr,n);
            
           
        }
	return 0;
}
