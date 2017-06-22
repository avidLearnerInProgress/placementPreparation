#include<bits/stdc++.h>
using namespace std;

int isSubset(int arr1[],int arr2[],int m,int n){
    map<int,int> mp;
    
    for(int i=0;i<m;i++){
        if(!mp[arr1[i]])
            mp[arr1[i]]=1;
        else
            mp[arr1[i]]++;
    }
    for(int i=0;i<n;i++){
        if(!mp[arr2[i]])
          return 0;
        mp[arr2[i]]--;
    }
    return 1;
}


int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int m,n;
            cin>>m>>n;
            
            
            int arr1[m];
            int arr2[n];
            
            for(int i=0;i<m;i++)cin>>arr1[i];
            for(int i=0;i<n;i++)cin>>arr2[i];
            
            int x=isSubset(arr1,arr2,m,n);
            if(x==1)cout<<"Yes"<<endl;
            if(x==0)cout<<"No"<<endl;
            
 
        }
	return 0;
}
