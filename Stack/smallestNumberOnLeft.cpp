#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)

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
            stack<int> st;
            
            F(0,n,i){
                
                while(!st.empty() && st.top()>=arr[i])
                    st.pop();
                    
                if(st.empty())cout<<-1<<" ";
                else cout<<st.top()<<" ";
                
                st.push(arr[i]);
                
            }
            cout<<endl;
        }
	return 0;
}
