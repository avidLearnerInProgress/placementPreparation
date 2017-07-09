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
            int n;
            cin>>n;
            int arr[n];
            F(0,n,i)cin>>arr[i];
            int top=arr[0];
            int index;
            int flag=1;
            for(int i=1;i<n;i++){
                if(arr[i]>=top){
                    index=i;
                    break;
                }
            }
            
            for(int i=index;i<n;i++){
                if(arr[i]<=arr[0]){
                    flag=0;break;
                }
            }
            
            if(flag==0)cout<<"NO"<<endl;
            
            else{
            for(int i=index-1;i>=1;i--)cout<<arr[i]<<" ";
            for(int i=n-1;i>=index;i--)cout<<arr[i]<<" ";
            cout<<arr[0]<<endl;
            
            }
 
        }
	return 0;
}
