#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            vector<int> deno={1,2,5,10,20,50,100,500,1000};
            
            vector<int> res;
            
            int n;cin>>n;
            for(int i=deno.size()-1;i>=0;i--){
                
                while(n>=deno[i]){
                    n-=deno[i];
                    res.push_back(deno[i]);
                }
            }
            
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
	return 0;
}
