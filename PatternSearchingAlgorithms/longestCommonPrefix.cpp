#include<bits/stdc++.h>
using namespace std;


string lCPUtil(string s1,string s2){
	
	int i,j;
	string result;
	for(i=0,j=0;i<s1.length()&& j<s2.length();i++,j++){
		if(s1[i]!=s2[j])break;
		result.push_back(s1[i]);
	}
	return result;
}


string lCP(string s[],int n){
	
	string result=s[0];
	
	for(int i=0;i<n;i++){
		result=lCPUtil(result,s[i]);
		
	}
	return result;
}



int main(){
	
	string s[]={"geeksforgeeks","geek","geeks","geezer"};
	int length=sizeof(s)/sizeof(s[0]);
	string result=lCP(s,length);
	if(result.length())cout<<result<<endl;
	else cout<<"Not found."<<endl;
	
}
