#include <bits/stdc++.h>
using namespace std;

#define size 26
#define F(a,b,var) for(int var=a;var<b;var++)

struct Trie{
    Trie *children[26];
    bool isLeaf;
    
    Trie(){
        F(0,26,i)children[i]=NULL;
        isLeaf=false;
    }
};

Trie *root=new Trie();

void insert(string s){
    
    Trie *node=root;
    F(0,s.length(),i){
        int index=((int)s[i]-(int)'a'); // could be a macro definition 
        if(node->children[index]==NULL)node->children[index]=new Trie();
        node=node->children[index];
    }
    node->isLeaf=true;
}

void searchAllWords(Trie *node,bool hash[],string s){
    if(node->isLeaf==true)cout<<s<<endl;
    F(0,size,i){
        if(hash[i]==true && node->children[i]!=NULL){
            char c=(char)i+(char)'a';
            searchAllWords(node->children[i],hash,s+c);
        }
    }
}


void printAllWords(char arr[],int n){
    Trie *node=root;
    string s="";
    bool hash[size];
    F(0,n,i){
        hash[(int)arr[i]-(int)'a']=true; //set only those characters present in array!
    }
    F(0,size,i){
       if(hash[i]==true && node->children[i]){
           s+=(char)i+(char)'a';
           searchAllWords(node->children[i],hash,s);
           s="";
       }
    }
}

int main()
{
    char Dict[][20] = {"go", "bat", "me", "eat",
                       "goal", "boy", "run"} ;
 
    // Root Node of Trie
    //Trie *root = new Trie();
    int n = sizeof(Dict)/sizeof(Dict[0]);
    for (int i=0; i<n; i++)
        insert(Dict[i]);
    char arr[] = {'e', 'o', 'b', 'a', 'm', 'g', 'l'} ;
    int N = sizeof(arr)/sizeof(arr[0]);
    printAllWords(arr,N);
}
