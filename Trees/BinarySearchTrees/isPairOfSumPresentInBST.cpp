#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};

bool isPairSumPresent(Node *root,int sum){
	
	Node *x=root;
	Node *y=root;
	int a,b;
	stack<Node *> s1,s2;
	
	while(1){
	while(x){
		s1.push(x);
		x=x->left;
	}
	
	while(y){
		s2.push(y);
		y=y->right;
	}
	
	
	a=s1.top()->data;
	b=s2.top()->data;
	
	if(s1.empty()|| s2.empty() || a>=b) return false;
	
	if(a+b==sum){
		cout<<"Pair Found: "<<a<<" + "<<b<<" = "<<sum<<endl;
		return true;
	}
	if(a+b<sum){
		x=s1.top()->right;
		s1.pop();
	}
	
	if(a+b>sum){
		y=s2.top()->left;
		s2.pop();
	}
	
	}
}
int main(){
	Node *root =  new Node(15);
    root->left = new Node(10);
    root->right = new Node(21);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->left->right->left= new Node(11);
    root->left->right->right = new Node(13); 
    root->right->left = new Node(16);
    root->right->right = new Node(25); 
    int sum = 41;

    if (isPairSumPresent(root, sum) == false)
        printf("\n No such values are found\n");
	
}
