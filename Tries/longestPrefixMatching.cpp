#include<bits/stdc++.h>
using namespace std;

#define SIZE 26

struct node{
	int data;
	node *children[26];
};	

struct trie{
	int count;
	node *root;
};

node *createNode(){
	node *temp=new node();
	temp->data=0;
	for(int i=0;i<26;i++)
		temp->children[i]=NULL;
	return temp;	
}


trie *initialize(){
	trie *tNode=new trie();
	tNode->root=createNode();
	tNode->count=0;
	return tNode;
}


void *insert(trie *t,char *key){
	
	int l=strlen(key);
	node *temp;
	t->count++;
	temp=t->root;
	for(int i=0;i<l;i++){
		int index=key[i]-97;
		if(!temp->children[index])
			temp->children[index]=createNode();
		temp=temp->children[index];
	}
	temp->data=t->count;
}


string prefixMatching(trie *t,char *key){
	
	int len=strlen(key);
	node *temp=t->root;
	int prematch=0;
	string S="";
	
	
	for(int i=0;i<len;i++){
		
		int index=key[i]-97;
		if(temp->children[index]){
			S+=key[i];
			temp=temp->children[index];
			if(temp->data)prematch=i+1;
		}
		else break;
	}
	if(!temp->data)return S.substr(0,prematch);
	else return S;
}



int main(void)
{
	struct trie *T = initialize();
	insert(T,"are");
	insert(T,"area");
	insert(T,"base");
	insert(T,"cat");
	insert(T,"cater");
	insert(T,"children");
	insert(T,"basement");
	cout<<prefixMatching(T,"caterer")<<endl;
	cout<<prefixMatching(T,"basemexy")<<endl;
	cout<<prefixMatching(T,"child")<<endl;
	return 0;
}
