#include<bits/stdc++.h>
using namespace std;


int pairExists(int arr[],int n){
    
    map<int,pair<int,int> > mp;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            int sum=arr[i]+arr[j];
            
            if(mp.find(sum)==mp.end())
                mp[sum]=make_pair(i,j);
                
            else{
                pair<int,int> prev=mp[sum];
                return 1;
            }    
            
            
            
        }
    } 
    
    return 0;
    
    
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
            
            int x=pairExists(arr,n);
            cout<<x<<endl;
        }
	return 0;
}
