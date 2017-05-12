#include<bits/stdc++.h>
using namespace std;

//using STL

int main()
{
	list<int> l;
	list<int>::iterator it;
	
	l.push_back(10);
	l.push_back(10);
	l.push_back(10);
	l.push_front(20);
	l.push_front(20);
	it=l.begin();
	advance(it,2);
	
	l.insert(it,30);
	
	for(it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	l.pop_front();
	l.pop_back();
	it=l.begin();
	advance(it,2);
	l.erase(it);
	
	
	
	
	
	
	for(it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
	
	return 0;
}
