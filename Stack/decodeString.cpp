#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            string s,res;
            cin>>s;
            stack<char> s1;
            for(int i=0;i<s.length();i++){
                
                if(s[i]!='[' && s[i]!=']')
                {
                    s1.push(s[i]);    
                }
                else if(s[i]==']'){
                    
                    string temp,count;
                    
                    if(s1.top()<'0' || s1.top()>'9'){
                        while(s1.top()<'0' || s1.top()>'9'){
                            temp=temp+s1.top();
                            s1.pop();
                            
                        }
                    }
                    
                    reverse(temp.begin(),temp.end());
                    
                    
                    while(!s1.empty() && s1.top()>='0' && s1.top()<='9'){
                        count=count+s1.top();
                        s1.pop();
                    }
                    
                    reverse(count.begin(),count.end());
                    int len=atoi(count.c_str());
                    
                    for(int j=0;j<len;j++){
                        for(int k=0;k<temp.length();k++){
                            s1.push(temp[k]);
                        }
                    }    
                }   
            }
               
                while(!s1.empty()){
                    res=res+s1.top();
                    s1.pop();
                }
                reverse(res.begin(),res.end());
                cout<<res<<endl;
        }
	return 0;
}
