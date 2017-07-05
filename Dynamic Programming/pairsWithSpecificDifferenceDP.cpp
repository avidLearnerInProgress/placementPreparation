#include<bits/stdc++.h>
using namespace std;

#define F1(a,b,var) for(int var=a;var<b;var++)
#define F2(a,b,var) for(int var=a;var>=b;var--)


int pairWithSpecificDifference(int arr[],int n,int k){
    
    sort(arr,arr+n);
    
    long long int maxSum=0;
    for(int i=n-1;i>0;){
        if(arr[i]-arr[i-1] <k){
                maxSum+=arr[i]+arr[i-1];
                
               i-=2;
        }   
        else i-=1;
    }
    return maxSum;
}

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int n;cin>>n;
            int arr[n];
            for(int i=0;i<n;i++)cin>>arr[i];
            int k;cin>>k;
            int res=pairWithSpecificDifference(arr,n,k);
            cout<<res<<endl;
        }
	return 0;
}
