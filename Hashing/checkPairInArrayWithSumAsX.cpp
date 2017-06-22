#include<bits/stdc++.h>
using namespace std;
bool b[2001];
int a[201];
int main()
{
	int t,k;
	cin>>t;
	while(t--){
	    
	    int n,sum,temp;
	    int b[1001]={0};
	    bool flag=false;
	    cin>>n>>sum;
	    vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin>>v[i];
	   
	    for(int i=0;i<n;i++){
	        temp=sum-v[i];
	        
	        if(temp>=0 && b[temp]==1){
	            cout<<"Yes"<<endl;
	            flag=true;
	            break;
	        }
	        b[v[i]]=1;
	    }
	    
	    if(!flag)cout<<"No"<<endl;
	}
	return 0;
}

