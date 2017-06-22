#include<bits/stdc++.h>
using namespace std;


#define F(a,b) for(int i=a;i<b;i++)
#define F1(a,b) for(char i=a;i<=b;i++)
#define F2(a) for(;i<a;i++)

struct Trie{
	
	unordered_map<char,Trie*> children;
	bool leaf;
	Trie(){
		leaf=false;
		F1('a','z'){
			children[i]=NULL;
		}
	}
};

Trie *root=NULL;

void insert(string s){
	
	Trie *itr=root;
	F(0,s.length()){
		Trie *next=itr->children[s[i]];
		if(next==NULL){
			next=new Trie();
			itr->children[s[i]]=next;
		}
		
		itr=next;
		
		if(i==(s.length()-1))
			itr->leaf=true;
		//cout<<"Inside Insert Loop"<<endl;	
	}
	
}

void displayContactsUtil(Trie *curr,string s){
	
	if(curr->leaf)cout<<s<<endl;
	
	F1('a','z'){
		Trie *temp=curr->children[i];
		if(temp!=NULL)
			displayContactsUtil(temp,s+(char)i);
	}
}


void displayContacts(string s){
	Trie *prev=root;
	string prefix="";
	int i;
	
	for(i=0;i<s.length();i++){ 
	//First time i Realized why macros won't always work... :p
	//after break value of i is needed outside this loop which can't be consumed if we use macros....
	//F(0,s.length()){

		prefix+=s[i];
		char lastChar=prefix[i];
		
		Trie *curr=prev->children[lastChar];
		if(curr==NULL){
			cout<<"No Suggestions Found For -> "<<prefix<<endl;
			i++;
			break;
		}
		
		cout<<"Suggestions For -> "<<prefix<<" are: "<<endl;
		displayContactsUtil(curr,prefix);
		prev=curr;
	}
	
	//F2(s.length()){
	for (;i<s.length();i++){	
		prefix+=(char)s[i];
		cout<<"No Suggestions Found For -> "<<prefix<<endl;			
	}
}


int main()
{
	root = new Trie();
    string contacts[] = {"gforgeeks","geeksquiz"};
    int n = sizeof(contacts)/sizeof(string);
    
    F(0,n)insert(contacts[i]);
    
    string query="gekk";
    displayContacts(query);
 
    return 0;
}
