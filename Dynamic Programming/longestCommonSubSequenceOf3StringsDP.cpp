#include <iostream>
using namespace std;

#define F(a,b,var) for(int var=a;var<=b;var++)

int LCS3Strings(string x,string y,string z,int m,int n,int o){
    int dp[m+1][n+1][o+1];
    
    F(0,m,i){
        F(0,n,j){
            F(0,o,k){
                
                if(i==0 || j==0 ||k==0)dp[i][j][k]=0;
                
                else if(x[i-1]==y[j-1]  && x[i-1]==z[k-1])
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else 
                    dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                
            }
        }
    }
            
            return dp[m][n][o];
}


int main() {
	//code
	
	string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";
 
    int m = X.length();
    int n = Y.length();
    int o = Z.length();
 
    cout << "Length of LCS is " << LCS3Strings(X, Y, Z, m, n, o);
 
	return 0;
}
