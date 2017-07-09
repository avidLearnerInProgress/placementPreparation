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
            string s;
            cin>>s;
            stack<int> st;
            st.push(-1);
            int res=0;
            
            F(0,s.length(),i){
                
                //while(!st.empty() && st.top()>=s[i])st.pop();
                
                if(s[i]=='(')st.push(i);
                else{
                    st.pop();
                    if(st.empty())st.push(i);
                    else res=max(res,i-st.top());
                }
            }
            
            cout<<res<<endl;
        }
	return 0;
}
