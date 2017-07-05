#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e6+5;
#define ll long long int

ll ncr(ll n,ll k)
{
    ll C[n+10][k+10];
    
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=min(i,k);j++)
        {
            if(j==0||j==i)
            C[i][j]=1;
            else
            C[i][j]=(C[i-1][j-1]%mod+C[i-1][j]%mod)%mod;
        }
    }
    return C[n][k]%mod;
}


ll t,n,m,k,c,res,ans;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(n<k) cout<<0<<endl;
		else
		cout<<ncr(n,k)%mod<<endl;
		
		
	}
	return 0;
}
