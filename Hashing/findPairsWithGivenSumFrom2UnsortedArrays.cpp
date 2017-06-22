#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int m,n,sum;
            cin>>m>>n>>sum;
            
            int arr1[m];
            int arr2[n];
            
            unordered_set<int> S;
            vector<pair<int,int> > v;
            
            F(0,m,i)cin>>arr1[i];
            F(0,n,i)cin>>arr2[i];
            
            F(0,m,i)S.insert(arr1[i]);
            
            F(0,n,i){
                
                if(S.find(sum-arr2[i])!=S.end()){
                    v.push_back(make_pair(sum-arr2[i],arr2[i]));
                }
            }
            
            if(!v.empty()){
                sort(v.begin(),v.end());
                
                int count=v.size()-1;  //TO remove that annoying , comming at the end while printing !! :(
                
                F(0,v.size(),i){
                    int x=v[i].first;
                    int y=v[i].second;
                    
                    cout<<x<<" "<<y;
                    if(count!=0){
                        cout<<", ";
                        count--;
                    }
                }        
            }
            else cout<<-1;
            cout<<endl;
        }
	return 0;
}
