#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)

void solve(string s){
    int n=s.length();
    
    int i=0;
    int j=0;
    int st=0;
    int e=0;
    int len=1;
    bool hash[256]={false};
    for(int j=0;j<n;j++){
        
        if(!hash[s[j]]){
            hash[s[j]]=true;
            
            if(len<j-i+1){
                len=j-i+1;
                st=i;
                e=j;
            }
        }
        
        else{
            while(s[i]!=s[j]){
                hash[s[i++]]=false;
                
            }
            i++;
        }
    }
    
    cout<<abs(st-e)+1<<endl;
    //cout<<endl;
}

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            string s;
            cin>>s;
            solve(s);
        }
	return 0;
}
