#include<bits/stdc++.h>
using namespace std;

//using stl

int main(){
	
	
	queue<int> q;
	q.push(10);
	
	int t=q.front();
	
	q.pop();
	
	cout<<t<<endl;
	cout<<q.size();
	
	deque<int> d;
	d.push_back(20);
	d.push_front(10);
	
	//deque<int>::iterator i;
	auto i=d.begin();
	i++;
	d.insert(i,30);
	
	for(i=d.begin();i!=d.end();i++)
		cout<<*i<<" ";
		cout<<endl;
	d.erase(d.begin(),d.begin()+1);
	
	for(i=d.begin();i!=d.end();i++)
		cout<<*i<<" ";
	cout<<endl;	
	d.clear();
		
	d.push_back(20);
	d.push_back(30);
	d.push_front(10);	
	d.push_front(40);	
	
	for(i=d.begin();i!=d.end();i++)
		cout<<*i<<" ";
		cout<<endl;
		
	cout<<d.back();
	d.pop_back();
	cout<<d.back();
	cout<<d.front();
	d.pop_front();
	cout<<d.front();
	
	
	//d.insert()
	//cout<<d.max_size();
	//cout<<d.front();
	
	
	
	
	return 0;
}
