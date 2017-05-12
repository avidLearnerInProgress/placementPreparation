#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T2;cin>>T2;
	while(T2--){
		
		stack<char> s;
		string str;cin>>str;
		
		for(int i=0;i<str.length();i++){
			s.push(str[i]);
		}
		for(int i=0;i<str.length();i++){
			cout<<s.top()<<endl;
			s.pop();
		}
	cout<<endl;	
	}
	return 0;
}
