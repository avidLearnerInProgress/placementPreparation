#include<bits/stdc++.h>
using namespace std;


int max(int a,int b){
    return ((a>b)?a:b);
}

int printMaxOfMin(int v[],int n){
    
    stack<int>s;
    
    vector<int> left(n+1);
    vector<int> right(n+1);
    
    for(int i=0;i<n;i++)
    {
        left[i]=-1;
        right[i]=n;
    }

    for(int i=0;i<n;i++){
        
        while(!s.empty() && v[s.top()]>=v[i])
            s.pop();
        
        if(!s.empty()) left[i]=s.top();
        
        s.push(i);
    }
    
    while(!s.empty())s.pop();
    
    for(int i=n-1;i>=0;i--){
        
        while(!s.empty() && v[s.top()]>=v[i])
            s.pop();
        
        if(!s.empty()) right[i]=s.top();
        
        s.push(i);
    }
    
    
    vector<int> ans(n+1);
    for(int i=0;i<=n;i++) 
        ans[i]=0;
    
    for(int i=0;i<n;i++){
        int len=right[i]-left[i]-1;
        
        ans[len]=max(v[i],ans[len]);
        
    }
    
    for(int i=n-1;i>=1;i--)
        ans[i]=max(ans[i], ans[i+1]);
    
     for (int i=1;i<=n;i++)
        cout<<ans[i]<<" ";    
}


int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
         int n;cin>>n;
         int v[n];
         for(int i=0;i<n;i++)
            cin>>v[i];
        
         printMaxOfMin(v,n);
         cout<<endl;
        }
	return 0;
}
