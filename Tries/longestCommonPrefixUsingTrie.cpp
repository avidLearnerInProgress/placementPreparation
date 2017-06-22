#include<bits/stdc++.h>
using namespace std;

#define F(a,b) for(int i=a;i<b;i++)
#define F1(a,b) for (int i=a;i<=b;i++)
#define F2(a,b) for(string a : b)

struct Trie{
	
	Trie *children[26];
	bool leaf;
	/*
	Trie(){
		leaf=false;
		F(0,26){
			children[i]=NULL;
		}
		
	}*/
};


Trie *getNode(){
	Trie *temp=new Trie();
	temp->leaf=false;
	F(0,26)
		temp->children[i]=NULL;
	return temp;
}

void insert(Trie *root,string s){
	
	Trie *temp=root;
	
	F(0,s.length()){
		
		int index=s[i]-'a';
		if(temp->children[index]==NULL)
			temp->children[index]=getNode();
		
		temp=temp->children[index];
			
	}
	temp->leaf=true;
	//temp->word.push_back(s);
}




int countChild(Trie *root,int *index){
	int count=0;
	
	F(0,26){
	//for(int i=0;i<26;i++){
		if(root->children[i]!=NULL){
			count++;
			*index=i;
		}
	}
	return count;
}



string walkTrie(Trie *root){
	
	Trie *temp=root;
	int index;
	string res;
	
	while(countChild(temp,&index)==1 && temp->leaf==false){
		
		temp=temp->children[index];
		res.push_back('a' + index);
	}
	return res;
}


bool search(Trie *root,string s){
	
	Trie *temp=root;
	
	F(0,s.length()){
		int index=s[i]-'A';
		if(temp->children[index]==NULL)
			return false;
		
		temp=temp->children[index];
			
	}
	return true;
}

int main(){
	
	string arr[]={"geeksforgeeks","geeks","geek","geezer"};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Trie* root=getNode();
 
    F(0,n)
        insert(root,arr[i]);
     
    string x=walkTrie(root);
    cout<<x<<endl;
    //cout<<"Not found"<<endl;
    
    return 0;
     
}


