#include<bits/stdc++.h>
using namespace std;


//resulting in unexpected error !
//http://www.geeksforgeeks.org/word-formation-using-concatenation-of-two-dictionary-words/

#define F(a,b,var) for(int var=a;var<b;var++)
#define F1(a,b,var) for(var=a;var<b;var++)

struct Trie{
    Trie *children[26];
    bool isLeaf;
    
    Trie(){
        F(0,26,i)children[i]=NULL;
        isLeaf=false;
    }
};

Trie *root=NULL;

void insert(Trie *root,string s){
    
    Trie *node=root;
    F(0,s.length(),i){
        int index=(int)s[i]-(int)'a'; // could be a macro definition 
        if(node->children[index]==NULL)node->children[index]=new Trie();
        node=node->children[index];
    }
    node->isLeaf=true;
}

int findPrefix(Trie *root,string s){
	
	Trie *node=root;
	int pos=-1,i;
	for(i=0;i<s.length();i++){
		int index=(int)s[i]-(int)'a'; // could be a macro definition 
		if(node->isLeaf==true)pos=i;
		if(node->children[index]!=NULL) return pos;
		node=node->children[index];
	}
	if(node!=NULL && node->isLeaf)return i;
}


bool isPossible(Trie *root,string word){
	
	int t1=findPrefix(root,word);
	cout<<t1<<endl;
	
	string s(word,t1,word.length()-(t1));
	int t2=findPrefix(root,s);
	cout<<t2<<endl;
	if(t1==-1)return false;
	return(t1+t2==word.length());
}

int main()
{
    // Let the given dictionary be following
    vector<string> dictionary = {"geeks", "forgeeks",
                                    "quiz", "geek"};
 
    string word = "geeksquiz"; //word to be formed
    Trie *root = new Trie();
    // insert all words of dictionary into trie
    for (int i=0; i<dictionary.size(); i++)
        insert(root,dictionary[i]);
 
    isPossible(root,word) ? cout << "Yes":
                             cout << "No";
 
    return 0;
}

