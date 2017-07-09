#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            stack<string> st;
            int n;cin>>n;
            
            string str[n];
            for(int i=0;i<n;i++)
                cin>>str[i];
                
            
            for(int i=0;i<n;i++)
            {
                if(!st.empty() && st.top()==str[i])
                   st.pop();
                else    
                    st.push(str[i]);
            }
	        cout<<st.size()<<endl;
        }
	return 0;
}
