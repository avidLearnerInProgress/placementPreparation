#include<bits/stdc++.h>
using namespace std;


//using STl

int main()
{
	list<int> l;
	list<int>::iterator it;
	int n;cin>>n;
	int x=1;
	for(int i=10*x;i<=10*n;){
		l.push_back(i);x++;i+=10;
	}
	
	for(it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
	l.reverse();
	
	for(it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
		
	
	
	
	return 0;
}
