#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)



int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int n,m;
    	    cin>>n>>m;
    	    int mat[n][m];
    	    for(int i=0;i<n;i++){
    	        for(int j=0;j<m;j++)
    	        cin>>mat[i][j];
    	    }
    	    int dp[n+1][m+1];
    	    memset(dp,0,sizeof(dp));
    	    for(int i=0;i<n;i++)
    	        dp[i][0]=mat[i][0];
    	        //cout<<i<<" "<<dp[i][0]<<" "<<mat[i][0]<<endl;
    	    
    	    for(int i=1;i<m;i++){
    	        for(int j=0;j<n;j++){
    	           int x=(j>0)?dp[j-1][i-1]+mat[j][i]:0;
    	           int y=(j<n-1)?dp[j+1][i-1]+mat[j][i]:0;
    	           int z=dp[j][i-1]+mat[j][i];
    	          // cout<<dp[j][i-1]<<" "<<mat[j][i-1]<<j<<i-1<<endl;
    	           dp[j][i]=max(x,max(y,z));
    	           //cout<<x<<" "<<y<<" "<<z<<endl;
    	        }
    	    }
    	 int mx=0;
    	 for(int i=0;i<n;i++)
    	    mx=max(mx,dp[i][m-1]);
    	 cout<<mx<<endl;
        }
	return 0;
}
