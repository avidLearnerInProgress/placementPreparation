
#include<bits/stdc++.h>
using namespace std;

void maxSumArray(int arr[],int n){
    
    int csf=arr[0];
    int msf=arr[0];
    
    for(int i=1;i<n;i++){
        
        csf=max(csf+arr[i],arr[i]);
        msf=max(msf,csf);
    }
   cout<<msf<<endl;
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
            for(int i=0;i<n;i++) cin>>arr[i];
            maxSumArray(arr,n);
        }
	return 0;
}
