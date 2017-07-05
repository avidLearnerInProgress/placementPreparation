#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        string str;
        cin>>str;
        stack<char> s;
        bool flag=true;
        for(int i=0;i<(int)str.size();i++){
            if(str[i]==')'){
                if(s.empty())
                 {
                    flag=false;
                    break;
                }
                char c=s.top();
                if(c!='('){
                    flag=false;
                    break;
                }
                else{
                    s.pop();
                    continue;
                }
            }
            if(str[i]=='}'){
                if(s.empty())
                {
                    flag=false;
                    break;
                }
                char c=s.top();
                if(c!='{'){
                    flag=false;
                    break;
                }
                else{
                    s.pop();
                    continue;
                }
            }
            if(str[i]==']'){
                if(s.empty())
                {
                    flag=false;
                    break;
                }
                char c=s.top();
                if(c!='['){
                    flag=false;
                    break;
                }
                else{
                    s.pop();
                    continue;
                }
            }
            s.push(str[i]);
        }
        if(!s.empty())
        flag=false;
        if(!flag)
        cout<<"not balanced\n";
        else
        cout<<"balanced\n";
    }
}
