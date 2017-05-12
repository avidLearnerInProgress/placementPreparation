#include<bits/stdc++.h>

using namespace std;

//using stl


int main()
{
	forward_list<int> f;
	forward_list<int>::iterator it;
	
	
	f.push_front(3);    //insert beginning 
	f.push_front(2);
	f.push_front(1); // 1-2-3
	
	it=f.begin();
	f.insert_after(it,4);   //insert after
	//cout<<f.size();
	int count =0;
	
	for(it=f.begin();it!=f.end();it++)
	cout<<*it<<endl;
	
	
	
	auto before_end = f.before_begin();  //insert at end 
	for (auto& _ : f)
  		++ before_end;
	f.insert_after(before_end,5);
	
	for(it=f.begin();it!=f.end();it++)
	cout<<*it<<" ";
	
	cout<<endl;
	
	f.pop_front(); //delete start
	
	
	f.reverse();
	f.pop_front();   //delete end 
	f.reverse();
	for(it=f.begin();it!=f.end();it++)
	cout<<*it<<" ";
	cout<<endl;
	it=f.begin();
	advance(it,1);
	f.erase_after(it);  //delete after position 
	
	for(it=f.begin();it!=f.end();it++)
	cout<<*it<<" ";
	cout<<endl;
	f.push_front(3);    
	f.push_front(2);
	f.push_front(1); 
	
	
	f.remove(1); //delete node with key
	for(it=f.begin();it!=f.end();it++)
	cout<<*it<<" ";
	
	return 0;
}
