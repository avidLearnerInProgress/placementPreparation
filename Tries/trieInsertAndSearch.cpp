#include<bits/stdc++.h>
using namespace std;



class TrieNode{
	
	
	TrieNode *children[26];
	bool isLeaf;
	
	public:
		TrieNode(){
			
			//TrieNode *t=NULL;
			for(int i=0;i<26;i++)
				children[i]=NULL;
			isLeaf=false;
		}
		
		void insert(string s){
			TrieNode *t=this;
			
			for(int i=0;i<s.length();i++){
				
				int index=s[i]-97;
				
				TrieNode *nn=new TrieNode();
				
				if(t->children[index]==NULL){
					t->children[index]=nn;
					if(i==s.length()-1)
						nn->isLeaf=true;
					t=nn;	
				}
				else{
					
					t=t->children[index];
					if(i==s.length()-1)
						t->isLeaf=true;
				}
			}
		}
		
		bool search(string s){
			
			TrieNode *t=this;
			int i=0;
			while(t!=NULL && i<s.length()){
				int index=s[i]-97;
				t=t->children[index];
				i++;
			}
			
			if(t!=NULL && t->isLeaf==1)return true;
			else 
				return false;
		}
		
};


int main(){
	
	int T;
	cin>>T;
	while(T--){
		int n;
        cin>>n;
        string key;
        string s[n];
        for(int i=0;i<n;i++)
        	cin>>s[i];
        cin>>key;
        
        TrieNode node;
        for(int i=0;i<n;i++)
        	node.insert(s[i]);
      
        int res=node.search(key);
        cout<<res<<endl;
        //else cout<<0<<endl;
        
	}
	
	
	
}
