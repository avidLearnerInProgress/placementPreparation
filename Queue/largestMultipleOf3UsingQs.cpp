#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int T;
	cin>>T;
	while(T--){
	
		int n;cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)cin>>vec[i];
		int sum=0;
		sort(vec.begin(),vec.end());
		queue<int> q1,q2,q3;
		
		for(int i=0;i<n;i++){
			
			sum+=vec[i];
			if(vec[i]%3==0)
				q1.push(vec[i]);
			
			if(vec[i]%3==1)
				q2.push(vec[i]);
			
			if(vec[i]%3==2)
				q3.push(vec[i]);	
			
		}
		
		vector<int> t1;
		
		
		if(sum%3==0){
			
		while(!q1.empty()){	
			t1.push_back(q1.front());
			q1.pop();
		 }	
		
		while(!q2.empty()){
			t1.push_back(q2.front());
			q2.pop();
		 }	
			
		while(!q3.empty()){	
			t1.push_back(q3.front());
			q3.pop();
		 }
		}
		
		if(sum%3==1)
		{
			if(!q1.empty())
			{
				 if(q2.size()>1){
					int x=q2.front();q2.pop();
					int y=q2.front();q2.pop();
					cout<<x<<" "<<y<<endl;
				 }
				 else cout<<"Error"<<endl;
			}
			else
			{
					int z=q2.front();q2.pop();
					cout<<z<<endl;
			}	
		}
		
		
		if(sum%3==2)
		{
			if(!q2.empty())
			{
				 if(q1.size()>1){
					int x=q1.front();q1.pop();
					int y=q1.front();q1.pop();
					cout<<x<<" "<<y<<endl;
				 }
				 else cout<<"Error"<<endl;
			}
			else
			{
					int z=q1.front();q1.pop();
					cout<<z<<endl;
			}	
		}
		
		
		
		while(!q1.empty()){
			t1.push_back(q1.front());
			q1.pop();
		}
		
		while(!q2.empty()){
			t1.push_back(q2.front());
			q2.pop();
		}
		
		while(!q2.empty()){
			t1.push_back(q2.front());
			q2.pop();
		}
		
		
		sort(t1.begin(),t1.end());
		
		for(int i=0;i<t1.size();i++)cout<<t1[i]<<" ";
			
		
	
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
