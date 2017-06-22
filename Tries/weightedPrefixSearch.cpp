#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)

struct Trie{
	
	Trie *children[26];
	int weight;
	Trie(){
		
		weight=INT_MIN;
		F(0,26,i)children[i]=NULL;
		
	}
};


Trie *root=NULL;

Trie *insert(string s,int i,int weight,Trie *root){
	
	Trie *node=root;
	int index=s[i]-'a';
	if(node->children[index]==NULL)node->children[index]=new Trie();
	node->children[index]->weight=max(node->children[index]->weight,weight);
	
	if(i+1!=s.length()){
		node->children[index]=insert(s,i+1,weight,node->children[index]);
	}
	return node;
}


int searchMaximum(string s,Trie *root){
	
	
	Trie *node=root;
	int ans=-1;
	F(0,s.length(),i){
		int index=s[i]-'a';
		if(node->children[index]==NULL)return -1;
		ans=node->children[index]->weight;
		node=node->children[index];
	}
	return ans;
}

int main()
{
    int n = 3;
    string str[3]={"geeks", "geeksfor", "geeksforgeeks"};
    int weight[] = {15, 30, 45};
    string search="geek";
	
	root=new Trie() ;
	F(0,n,i){
		root=insert(str[i],0,weight[i],root);
	}
 
    cout<<searchMaximum(search,root)<<endl;
 
    return 0;
}
