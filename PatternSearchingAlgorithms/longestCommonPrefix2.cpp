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


string lCP(string s[],int low,int high){
	
	if(low==high)return s[low];
	int mid=low+(high-low)/2;
	
	string s1=lCP(s,low,mid);
	string s2=lCP(s,mid+1,high);
	
	return (lCPUtil(s1,s2));
}



int main(){
	
	string s[]={"geeksforgeeks","geek","geeks","geezer"};
	int length=sizeof(s)/sizeof(s[0]);
	string result=lCP(s,0,length-1);
	if(result.length())cout<<result<<endl;
	else cout<<"Not found."<<endl;
	
}
