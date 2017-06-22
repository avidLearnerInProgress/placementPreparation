#include<bits/stdc++.h>
using namespace std;
/*
{ "A", "C" },
{ "B", "C" },
{ "C", "F" },
{ "D", "E" },
{ "E", "F" },
{ "F", "F" } 
*/

int FunC(map<string,int> &cnt,map<string,vector<string>> &rmp,vector<string> &s,string str){
    
    if(!s.size())return 0;
    if(cnt[str]!=0)return cnt[str];
    for(auto it=s.begin();it!=s.end();it++){
        return cnt[str]+=FunC(cnt,rmp,rmp[*it],*it)+s.size();
    }
}

int main(){
    
    map<string,string> mp;
    map<string,vector<string> > rmp;
    map<string,int> cnt;
    
    int n;
    cin>>n;
    while(n--){
        string s1,s2;
        cin>>s1>>s2;
        mp.insert(pair<string,string>(s1,s2));
        cnt.insert(pair<string,int>(s1,0));
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        rmp[it->second].push_back(it->first);
    }
    
    for(auto it=rmp.begin();it!=rmp.end();it++){
        cnt[it->first]=FunC(cnt,rmp,it->second,it->first);
    }
    
    for(auto it=cnt.begin();it!=cnt.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}
