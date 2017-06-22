#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)

#define row 4
#define col 5

struct Trie{
	
	Trie *children[2];
	bool isLeaf;
	
	Trie(){
		
		children[0]=children[1]=NULL;
		isLeaf=false;
	}
};


bool insert(int a[][col],int n,Trie *node){
	
	
	//cout<<"Into insert"<<endl;
	F(0,col,j){
	
		if(!node->children[a[n][j]])
			node->children[a[n][j]]=new Trie();
		node=node->children[a[n][j]];
	}	
	if(node->isLeaf)return 0;
	node->isLeaf=true;
	return 1;
	
}


void unique(int arr[][col]){
	
	Trie *root=new Trie();
	//cout<<"Into"<<endl;
	//int i,j;
	F(0,row,i){
		if(insert(arr,i,root)){
			F(0,col,j){
				cout<<arr[i][j]<<" ";
			}	
			cout<<endl;	
		}
	}
}


int main()
{
	int M[row][col] = {{0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };
    unique(M);
	return 0;
}
 
 

