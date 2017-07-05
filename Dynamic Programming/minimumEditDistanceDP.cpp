#include<bits/stdc++.h>
using namespace std;

int editDist(string s1,string s2,int m,int n){
    
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            
            if(i==0)
                dp[i][j]=j;
                
            else if(j==0)
                dp[i][j]=i;
                
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
                
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            
        }
    }
    return dp[m][n];
}



int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int m,n;
            cin>>m>>n;
            
            string s1,s2;
            cin>>s1>>s2;
            
            int minimum=editDist(s1,s2,m,n);
            cout<<minimum<<endl;
        }
	return 0;
}
