#include<bits/stdc++.h>
using namespace std;



bool compare(const pair<char, pair<int, int>> &a , const pair<char, pair<int, int>> &b){
	return a.second.second>b.second.second;
}


int main(){
	
	int n;
	cin>>n;
	char id;
	int deadline;
	int profit;	
	
	vector< pair < char,pair<int,int>>> m;
	
	for(int i=0;i<n;i++){
		cin>>id;
		cin>>deadline;
		cin>>profit;
		
		m.push_back(make_pair(id,make_pair(deadline,profit)));
		
	}
	sort(m.begin(),m.end(),compare);
	
	cout<<"Job Id"<<"\t"<<"Deadline"<<"\t"<<"Profit"<<endl;
	for(auto it=m.begin();it!=m.end();it++){
		cout<<(*it).first<<"\t"<<(*it).second.first<<"\t"<<(*it).second.second<<"\n";
	}
	
	
	int t=0,total_profit=0;
	for(auto it=m.begin();it!=m.end();it++){
		
		if(t<(*it).second.first){
			cout<<(*it).first<<" ";
			t++;
			total_profit+=(*it).second.second;
		}		
			
	}
	cout<<total_profit<<endl;

}
