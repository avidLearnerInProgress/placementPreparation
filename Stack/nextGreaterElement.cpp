#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int T;cin>>T;
	while(T--){
    int n;cin>>n;
    vector<int> v(n);
    
    vector<signed int> res(n);
    stack <int> s;
    for(int i=0;i<n;i++)
        cin>>v[i];
  
		//cout<<v[n-1]<<"->"<<-1<<endl;
		res.push_back(-1);
		s.push(v[n-1]);
		
		for(int i=n-2;i>=0;i--){
				
				if(s.top()>v[i]){
				//cout<<v[i]<<"->"<<s.top()<<endl;
					res.push_back(s.top());
				}	
				else{
					while(!s.empty()&& s.top()<v[i])
						s.pop();
					
					if(s.empty()){
					//cout<<v[i]<<"->"<<-1<<endl;
						res.push_back(-1);
						
					}
					else 
						res.push_back(s.top());
					//cout<<v[i]<<"->"<<s.top()<<endl;
				}
				s.push(v[i]);
		}
		reverse(res.begin(),res.end());
		for(int i=0;i<n;i++)
			cout<<res[i]<<" ";
		
		cout<<endl;
		}
    //for()
}
