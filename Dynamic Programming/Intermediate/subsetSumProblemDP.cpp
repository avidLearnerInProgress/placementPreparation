#include<bits/stdc++.h>
using namespace std;

bool subSetSum(int arr[],int s,int n){
    
    bool dp[s+1][n+1];
    
    
    for(int i=0;i<=s;i++){
        for(int j=0;j<n;j++){
            
            if(i==0)dp[0][j]=true;
            
            else if(j==0)dp[i][0]=false;
            
            else{
                dp[i][j]=dp[i][j-1];
                if(arr[j]<=i){
                    dp[i][j]= dp[i][j] || dp[i-arr[j]][j-1];
                }
            }
            
        }
    }
    return dp[s][n-1];
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
            int sum=0;
            for(int i=0;i<n;i++){
                    cin>>arr[i];
                    
            }  
            for(int i=0;i<n;i++){sum+=arr[i];}
            
            if(sum%2!=0)cout<<"NO"<<endl;
            else{
                
                sum/=2;
                if(subSetSum(arr,sum,n)==true)
                    cout<<"YES"<<endl;
                else
	                cout<<"NO"<<endl;    
            }        
            
        }
	return 0;
}
