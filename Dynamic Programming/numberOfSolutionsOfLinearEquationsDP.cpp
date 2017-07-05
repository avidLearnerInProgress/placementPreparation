#include <bits/stdc++.h>
using namespace std;

int linearEqSolutions(int coeff[],int n,int rhs){
    
    int dp[rhs+1];
    memset(dp,0,sizeof(dp));
    
    dp[0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=coeff[i];j<=rhs;j++){
            dp[j]+=dp[j-coeff[i]];
            cout<<dp[j]<<" ";
        }
        cout<<endl;
    }
   cout<<dp[rhs]<<endl;
}


int main() {
	//code
	
	int coeff[]={2,2,5};
	int n=sizeof(coeff)/sizeof(coeff[0]);
	int rhs=4;
	linearEqSolutions(coeff,n,rhs);
	
	
	return 0;
}
