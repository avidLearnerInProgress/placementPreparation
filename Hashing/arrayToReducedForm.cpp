#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    unordered_map<int,int> mp;
    
    int temp[n];
    memcpy(temp,arr,n*sizeof(int));
    
    sort(temp,temp+n);
    
    int val=0;
    
    for(int i=0;i<n;i++)mp[temp[i]]=val++;
    
    for(int i=0;i<n;i++)arr[i]=mp[arr[i]];
    
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    
    cout<<endl;
    
    
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
            
            solve(arr,n);
 
        }
	return 0;
}
