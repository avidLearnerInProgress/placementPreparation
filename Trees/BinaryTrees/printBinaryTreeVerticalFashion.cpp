#include<bits/stdc++.h>
using namespace std;


//For representation: http://www.geeksforgeeks.org/print-binary-tree-vertical-order/

struct Node{
	int data;
	struct Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

void printVerticalUtil(Node *root, int lvl, multimap<int,int> &mp){
    if(!root)
        return;
    mp.insert(make_pair(lvl,root->data));
    printVerticalUtil(root->left,lvl-1,mp);
    printVerticalUtil(root->right,lvl+1,mp);
}
 
void printVertical(Node *root){
    multimap<int,int> mp;
    printVerticalUtil(root,0,mp);
 
    multimap<int,int>::iterator it;
    for(it = mp.begin(); it != mp.end(); ){
        int tmp = it->first;
        while(it->first == tmp && it!= mp.end()){
            cout<<it->second<<" ";
            it++;
        }
        cout<<endl;
    }
}

int main(){
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	printVertical(root);
	
}





