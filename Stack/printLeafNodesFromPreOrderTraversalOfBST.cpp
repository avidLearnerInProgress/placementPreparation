#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>s;
    for(int i=0,j=1;j<n;j++,i++){
            bool found=false;
            if(arr[i]>arr[j])
                s.push(arr[i]);
            else{
                while(!s.empty()){
                    if(arr[j]>s.top()){
                        s.pop();
                        found=true;
                    }
                    else break;
                    
                }
                if(found) cout<<arr[i]<<" ";
            }
            
        
    }cout<<arr[n-1];
    cout<<endl;

    }
}


