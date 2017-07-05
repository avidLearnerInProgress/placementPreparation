#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            
            
            int n;cin>>n;
            vector<int> v(n);
            stack<int> s;
            int ans[n];
            
            for(int i=0;i<n;i++){
                cin>>v[i];
            }
            
            ans[0]=1;     // Span value of first element is always 1
            s.push(0);  
            
                  // If stack becomes empty, then price[i] is greater than all elements
      // on left of it, i.e., price[0], price[1],..price[i-1].  Else price[i]
      // is greater than elements after top of stack

            
            
            for(int i=1;i<=n;i++){
                
                
      // Pop elements from stack while stack is not empty and top of
      // stack is smaller than price[i]

                
                while(!s.empty() && v[s.top()]<=v[i])
                    s.pop();
                
                if(s.empty())    
                    ans[i]=i+1;
                else
                    ans[i]=i-s.top();
                
                s.push(i);
                
            }
            
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            
            cout<<endl;
            
            
            
            
 
        }
	return 0;
}
