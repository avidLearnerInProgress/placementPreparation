#include<bits/stdc++.h>
using namespace std;


int findMaxLengthSubstring(string str){
	
	stack<int> s;
	int res=0;
	s.push(-1);
	
	int length=str.length();
	
	for(int i=0;i<length;i++){
		
		if(str[i]=='(')s.push(i);
		
		else{
			s.pop();
			if(!s.empty())
				res=max(res,i-s.top());
			else s.push(i);
			
		}
	}
	return res;
}


int main()
{
    string str = "((()()";
    cout << findMaxLengthSubstring(str) << endl;
    str = "()(()))))";
    cout << findMaxLengthSubstring(str) << endl ;
 
    return 0;
}
