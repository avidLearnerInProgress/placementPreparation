#include<bits/stdc++.h>
using namespace std;
#define max 256

#define For(a,b) for(int i=a;i<b;i++)

class Node{
	
	list<int> *indexes;
	Node *children[max];
	public:
	Node(){
		indexes=new list<int>;
		For(0,max){
			children[i]=NULL;
		}
	}
	
	void insertNode(string s,int index);
	list<int> *search(string pat);
};

class SuffixTree{
	
	Node root;
	public:
		SuffixTree(string txt){
			
			For(0,txt.length()){
				root.insertNode(txt.substr(i),i);
			}
		}
	
	void search(string pat);
		
};

void Node::insertNode(string s,int index){
	
	indexes->push_front(index);
	if(s.length()>0){
		
		char x=s[0];
		
		if(children[x]==NULL)
			children[x]=new Node();
	
		children[x]->insertNode(s.substr(1),index+1);
			
	}
}


list<int>* Node::search(string s){
	if(s.length()==0)return indexes;
	
	else if(children[s[0]]==NULL) return NULL;
	else 
		return children[s[0]]->search(s.substr(1));
	
}

void SuffixTree::search(string s){
	
	list<int> *result=root.search(s);
	if(result==NULL)cout<<"Not Found"<<endl;
	
	else{
		
		for(auto it=result->begin();it!=result->end();it++){
			
			cout<<"Found at: "<<(*it)-s.length()<<endl;
		}
	}
}

int main()
{
    
    string txt = "geeksforgeeks.org";
    SuffixTree S(txt);
 
    cout << "Search for 'ee'" << endl;
    S.search("ee");
 
    cout << "\nSearch for 'geek'" << endl;
    S.search("geek");
 
    cout << "\nSearch for 'quiz'" << endl;
    S.search("quiz");
 
    cout << "\nSearch for 'forgeeks'" << endl;
    S.search("forgeeks");
 
    return 0;
}
