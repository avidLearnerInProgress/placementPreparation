#include<bits/stdc++.h>
#include<cstring>

using namespace std;

int isOperand(char x){
	
	//char x=tolower(i);
	if(x>='a' && x<='z' || x>='A' && x<='Z')
		return 1;
	
	else return 0;
	
}

int isPrec(char x){
	switch(x){
		
		case '+':
		case '-':
			return 1;
			 
		case '*':
		case '/':
			return 2;
		
		case '^':
			return 3;
	}
	return -1;
}


int main(){
	
	stack<char> iTp;
	string s;cin>>s;
	int length=s.length();
	
	string o="";
	int k=0;
	for(int i=0;i<length;i++){
		if(isOperand(s[i]))
			o.push_back(s[i]);
		
		else if(s[i]=='(')
			iTp.push(s[i]);
		
		else if(s[i]==')'){
			while(!iTp.empty() && iTp.top()!='('){
			char temp=iTp.top();
				o.push_back(temp);
				iTp.pop();
			}	
			if(!iTp.empty() && iTp.top()!='(')
				return -1; //invalid it means that ) is encountered but ( isn't there. i.e."())"   
			else
				iTp.pop();
		}
		else{
			while(!iTp.empty() && isPrec(s[i])<= isPrec(iTp.top())){
				char temp=iTp.top();
				o.push_back(temp);
				iTp.pop();
		}
			iTp.push(s[i]);
	}
	}
	while(!iTp.empty()){
		char temp=iTp.top();
				o.push_back(temp);
				iTp.pop();
	}
	
	cout<<o<<endl;
	
	return 0;
}
