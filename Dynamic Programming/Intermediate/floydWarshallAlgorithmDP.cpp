#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int v;
            cin>>v;
            
            int arr[v][v];
            F(0,v,i){
                F(0,v,j){
                    cin>>arr[i][j];
                }
            }
            
            int dp[v][v];
            
            F(0,v,i){
                F(0,v,j){
                    dp[i][j]=arr[i][j];
                }
            }
            
            F(0,v,k){
                F(0,v,i){
                    F(0,v,j){
                        if(dp[i][j]>dp[i][k]+dp[k][j])
                            dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
            
            F(0,v,i){
                F(0,v,j){
                   cout<<dp[i][j]<<" ";
                }
            }
            
            cout<<endl;
        }
	return 0;
}
