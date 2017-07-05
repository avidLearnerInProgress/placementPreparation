#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)
#define F1(a,b,var) for(int var=a;var>=b;var--)
int longestBitonicSeq(int arr[],int n){
    
    int lis[n],lds[n];
    
    F(0,n,i){
        lis[i]=1;
        lds[i]=1;
    }
    
    F(1,n,i){
        F(0,i,j){
            
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
                
        }
    }
    
    F1(n-2,0,i){
        F1(n-1,i,j){
            if(arr[i]>arr[j] && lds[i]<lds[j]+1)
                lds[i]=lds[j]+1;
        }
    }
    
    int _max=lis[0]+lds[0]-1;
    //int i,j;
    F(1,n,i){
         _max=max(_max,lis[i]+lds[i]-1);
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
            
            cout<<longestBitonicSeq(arr,n)<<endl;
 
        }
	return 0;
}
