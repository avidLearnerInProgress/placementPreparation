#include<bits/stdc++.h>
using namespace std;

//#define F(a,b,var) for(var=a;var<b;var++)

int msis(int v[],int n){
    int dp[n];
    
    int i,j;
    int max=INT_MIN;
    for(int i=0;i<n;i++)dp[i]=v[i];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && dp[i]<dp[j]+v[i])
                dp[i]=dp[j]+v[i];
        }
    }
    /*for(int i=0;i<n;i++)cout<<dp[i]<<" ";
    cout<<endl;*/
    for(int i=0;i<n;i++)if(dp[i]>max)max=dp[i];
    //cout<<max<<endl;
    return max;
    
}


int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            
            int n;cin>>n;
            int v[n];
            int i;
            for(int i=0;i<n;i++)cin>>v[i];
            int res=msis(v,n);
            cout<<res<<endl;
            
        }
	return 0;
}
