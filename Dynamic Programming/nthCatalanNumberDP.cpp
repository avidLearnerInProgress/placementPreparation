#include<bits/stdc++.h>
using namespace std;

#define ui unsigned long int
#define ll long long int

const int mod=1e9+7;

ui ncr(int n,int k)
{
    if(k>n-k)
        k=n-k;
    ui res=1;
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

ui catalanNumber(ui n){
    
    ui res=ncr(2*n,n);
   // v.push_back(res/(n+1));
   cout<<res/(n+1)<<endl;
}

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            ui n;
            cin>>n;
            //vector<ui> v(n);
            //for(ui i=1;i<=n;i++){
            catalanNumber(n);
            
           /* for(ui i=1;i<=n;i++)
                cout<<v[i]<<endl;*/
        }
	return 0;
}
