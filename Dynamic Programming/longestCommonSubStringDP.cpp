#include<bits/stdc++.h>
using namespace std;

int LCS(string &x,string &y){
    
    int m=x.length();
    int n=y.length();
    
    int _LCS[m+1][n+1];
    int res=0;
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            
            if(i==0||j==0)_LCS[i][j]=0;
            
            else if(x[i-1]==y[j-1]){
                _LCS[i][j]=_LCS[i-1][j-1]+1;
                res=max(res,_LCS[i][j]);
            }
            else _LCS[i][j]=0;
        }
    }
    return res;
    
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
            string s1;cin>>s1;
            string s2;cin>>s2;
            int x=LCS(s1,s2);
            cout<<x<<endl;
        }
	return 0;
}
