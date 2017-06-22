#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	set < pair <int,string> > s;
	map < string,int > mp;
	int i,n,k;
	cin>>n>>k;
	while(n--)
	{
		string s1;
		cin>>s1;
		if(mp.find(s1)!=mp.end())
		mp[s1]++;
		else
		mp[s1]=1;
	}
	map <string,int>::iterator it=mp.begin();
	while(it!=mp.end())
	{
		pair <int,string> mp=make_pair(it->second,it->first);
		s.insert(mp);
		it++;
	}
	set < pair <int,string> >::iterator it1=s.end();
	it1--;
	while(it1!=s.begin()&&k>1)
	{
		cout<<it1->first<<" "<<it1->second<<" ";
		k--;
		it1--;
	}
	cout<<it1->first<<" "<<it1->second<<" ";
	return 0;
}
