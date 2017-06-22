#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t,i,j,n,k, m;
        cin>>t;
        while(t--)
        {
            cin>>n;
            int a[n+1];
            for(i=0;i<n;i++)
                cin>>a[i];
            
            map<int,int> mp;
            int ans=0,sum=0;
            for(i=0;i<n;i++)
            {
                int sum=0;
                for(j=i;j<n;j++)
                {
                    sum+=a[j];
                    if(sum==0)
                        ans++;
                    
                }
            }
            cout<<ans<<"\n";
        }
	return 0;
}
