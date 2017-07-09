#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)

bool wordMatch(string s,vector<string> &v){
    if(v.size()==0)return false;
    vector<bool> dp(v.size()+1,false);
    
    dp[0]=true;
    
    for(int i=1;i<=s.size();i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j]){
                string str=s.substr(j,i-j);
                auto it=find(v.begin(),v.end(),str);
                if(it!=v.end()){
                    dp[i]=true;
                    break;
                }
            }        
        }
                
    }
    return dp[s.size()];
}



int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int dictLength;
            cin>>dictLength;
            vector<string> v(dictLength);
            unordered_set<string> us;
            F(0,dictLength,i)cin>>v[i];
           /// F(0,dictLength,i)us.insert(v[i]);
            string s;
            cin>>s;
            if(wordMatch(s,v))cout<<1<<endl;
            else cout<<0<<endl;
            
        }
	return 0;
}
