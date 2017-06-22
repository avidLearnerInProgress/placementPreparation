#include<bits/stdc++.h>
using namespace std;


struct Trie{
	Trie *children[26];
	bool leaf;
	int freq;
	
	Trie(){
		leaf=false;
		freq=1;
		for(int i=0;i<26;i++)children[i]=NULL;
	}
};

Trie *getNode(){
	Trie *temp=new Trie();
	return temp;
}

void insert_trie(Trie *root,string s){
	
	Trie *temp=root;
	for(int i=0;i<s.length();i++){
		
		int index=(int)(s[i]-'a');
		
		if(temp->children[index]==NULL)temp->children[index]=getNode();
		else
			temp->children[index]->freq++;
		
		temp=temp->children[index];
	}
	
}

bool search_trie(Trie *root,string s){
	Trie *temp=root;
	for(int i=0;i<s.length();i++){
		
		int index=(int)(s[i]-'a');
		if(temp->children[index]==NULL)return false;
		temp=temp->children[index];
		return (temp!=NULL && temp->leaf==true);
	}
}

string shortest_uniqueprefix(Trie *root,string s){
	Trie *temp=root;
	string x="";
	for(int i=0;i<s.length();i++){
		int index=(int)(s[i]-'a');
		if(temp->children[index]==NULL)return x;
		
		if(temp->children[index]->freq==1){
			x+=s[i];
			return x;
		}
		
		else{
			x+=s[i];
			temp=temp->children[index];
		}
	}
	return x;
}

int main(){
	Trie *root=getNode();
    string c;
    int n,m;
    cout<<"Input no of string u wanna enter"<<endl;
    cin >> n;
    int i;
    for( i = 0; i < n ;i++)
    {
        cin >> c;
        insert_trie(root,c);
    }
    cout<<"Enter query string earlier entered in trie\n";
    int ind = 0;
    string lo = "";
    string prefix;
    //for(i = 0 ; i<n ; i++)  //for all strings just repeat what u entered as the input 
    //{
        cin >>prefix;
        lo = shortest_uniqueprefix(root,prefix);
        cout<<lo<<endl;
    //}
    return 0;
}
