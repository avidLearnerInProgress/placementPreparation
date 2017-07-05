#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)
#define F1(a,b,var) for(int var=a;var>=b;var--)

int longestSUMBitonicSeq(int arr[],int n){
    
    int lis[n],lds[n];
    
    F(0,n,i){
        lis[i]=arr[i];
        lds[i]=arr[i];
    }
    
    F(1,n,i){
        F(0,i,j){
            
            if(arr[i]>arr[j] && lis[i]<lis[j]+arr[i])
                lis[i]=lis[j]+arr[i];
                
        }
    }
    
    F1(n-2,0,i){
        F1(n-1,i,j){
            if(arr[i]>arr[j] && lds[i]<lds[j]+arr[i])
                lds[i]=lds[j]+arr[i];
        }
    }
    
    int _max=0;
    //int i,j;
    F(0,n,i){
         _max=max(_max,(lis[i]+lds[i]-arr[i]));
    }
    return _max;
}

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
            
            cout<<longestSUMBitonicSeq(arr,n)<<endl;
 
        }
	return 0;
}
