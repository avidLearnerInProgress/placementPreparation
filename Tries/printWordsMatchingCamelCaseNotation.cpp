#include<bits/stdc++.h>
using namespace std;

#define F(a,b) for(int i=a;i<b;i++)
#define F1(a,b) for (int i=a;i<=b;i++)
#define F2(a,b) for(string a : b)

struct Trie{
	
	Trie *children[26];
	bool leaf;
	list<string> word;
	public:
	Trie(){
		leaf=false;
		F(0,26){
			children[i]=NULL;
		}
		
	}
};


Trie *getNode(){
	Trie *temp=new Trie();
	return temp;
}

void insert(Trie *root,string s){
	
	Trie *temp=root;
	
	F(0,s.length()){
		if(islower(s[i]))
			continue;
		
		int index=s[i]-'A';
		if(temp->children[index]==NULL)
			temp->children[index]=getNode();
		
		temp=temp->children[index];
			
	}
	temp->leaf=true;
	temp->word.push_back(s);
}

void printAllWords(Trie *node){
	
	Trie *root=node;
	string x;
	if(root->leaf)
		F2(x,root->word)
			cout<<x<<endl;
			
	F(0,26){
		Trie *temp=root->children[i];
		if(temp)
			printAllWords(temp);  //temp : child
	}
}


bool search(Trie *root,string s){
	
	Trie *temp=root;
	
	F(0,s.length()){
		int index=s[i]-'A';
		if(temp->children[index]==NULL)
			return false;
		
		temp=temp->children[index];
			
	}
	printAllWords(temp);
	return true;
}

int main(){
	
	vector<string> dict={
        "Hi", "Hello", "HelloWorld", "HiTech", "HiGeek",
        "HiTechWorld", "HiTechCity", "HiTechLab"
    };
    
    string pattern="HT";
    Trie* root=getNode();
 
    F2(word,dict)
        insert(root, word);
 
    if (!search(root,pattern))
        cout << "No match found";
    
    return 0;
     
}


