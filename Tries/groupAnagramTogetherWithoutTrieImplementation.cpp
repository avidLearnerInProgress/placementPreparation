#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)

//Naive Approach without trie

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        {   
            int n;cin>>n;
            
            string v[n];
            
            F(0,n,i)cin>>v[i];
            
            map<string,int> m;
            
            F(0,n,i) sort(v[i].begin(),v[i].end());
            
            /*F(0,n,i)cout<<v[i]<<" ";
            cout<<endl;
            */
            F(0,n,i) m[v[i]]++;
            
            vector<int> vec;
            for(auto it=m.begin();it!=m.end();it++)
                vec.push_back(it->second);
            
            sort(vec.begin(),vec.end());
            F(0,vec.size(),i)cout<<vec[i]<<" ";
            
            cout<<endl;
        }
	return 0;
}
