#include <iostream>
using namespace std;

bool Subset(int A[],int n,int sum){

    bool dp[sum+1][n];

    for(int i=0;i<=sum;i++)
    for(int j=0;j<n;j++)
    {

        if(i==0)
        dp[0][j]=true;

        else if(j==0)
        dp[i][0]=false;

        else
        {
            dp[i][j]=dp[i][j-1];
            if(A[j]<=i)
            dp[i][j]=dp[i-A[j]][j-1]||dp[i][j];

        }

    }

return dp[sum][n-1];
}

int main() {
	//code
	int T,k;
	cin>>T;
	for(k=0;k<T;k++)
	{
	    int N;
	    cin>>N;
	    int A[N],sum=0;
	    for(int i=0;i<N;i++){
	    cin>>A[i];
	    sum+=A[i];
	    }
	    if(sum%2!=0)
	    cout<<"NO\n";
	    else{
	    sum=sum/2;
	    if(Subset(A,N,sum)==true)
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	    }
	}
	return 0;
}

