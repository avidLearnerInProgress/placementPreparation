#include<bits/stdc++.h>
using namespace std;

string lCP(vector<string> &v,int n){
	
	auto it=min_element(v.begin(),v.end());
	cout<<*it<<endl;
	string minEle=*it;
	
	cout<<minEle<<endl;
	
	int minElement=minEle.length();
	string result="";
	for(int i=0;i<minElement;i++){
		char temp=v[0][i];
		for(int j=1;j<n;j++)
			if(v[j][i]!=temp)return result;
			
		result.push_back(temp);
	}
	return result;
}


int main(){
	
	vector<string> v;
	v.push_back("geeksforgeeks");
	v.push_back("geeks");
	v.push_back("geek");
	v.push_back("geezer");
	
	int n=v.size();
	string result=lCP(v,n);
	if(result.length())cout<<"LCP is: "<<result<<endl;
	else cout<<"Not Found."<<endl;
	
}
