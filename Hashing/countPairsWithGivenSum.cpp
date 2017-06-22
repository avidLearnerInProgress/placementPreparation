#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int n,k;
            cin>>n>>k;
            int arr[n];
            
            for(int i=0;i<n;i++)cin>>arr[i];
            
            unordered_map<int,int> mp;
            
            for(int i=0;i<n;i++){
                mp[arr[i]]++;
            }
            
            int count=0;
            for(int i=0;i<n;i++){
                
                count+=mp[k-arr[i]];
                
                if(k-arr[i]==arr[i])count--;
            }
            
            cout<<count/2<<endl;;
            
 
        }
	return 0;
}

