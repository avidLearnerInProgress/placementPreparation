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
            string x;
    	    cin>>x;
    	    stack<int> S;
    	    F(0,x.size(),i)
    	    {
    	        if(x[i]>='0' && x[i]<='9')S.push(int(x[i]-'0'));
    	        else
    	        {
    	            int a=int(S.top());S.pop();
    	            int b=int(S.top());S.pop();
    	            if(x[i]=='+')
    	            S.push(a+b);
    	            else if(x[i]=='-')
    	            S.push(b-a);
    	            else if(x[i]=='*')
    	            S.push(a*b);
    	            else if(x[i]=='/')
    	            S.push(b/a);
    	        }
    	    }
    	    cout<<S.top()<<endl;
        }
	return 0;
}
