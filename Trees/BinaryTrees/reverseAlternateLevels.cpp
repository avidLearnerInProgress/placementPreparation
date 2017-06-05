#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};

void preOrder(Node *root1,Node *root2,int lvl){
	if(root1==NULL && root2==NULL)return;
	
	if(lvl%2==0)swap(root1->data,root2->data);
	preOrder(root1->left,root2->right,lvl+1);
	preOrder(root1->right,root2->left,lvl+1);
	
}

void reverseAlternate(Node *root){
	preOrder(root->left,root->right,0);
}


void print(Node *root)
{
    if (root == NULL)
       return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{
    Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');
 
    cout << "Inorder Traversal of given tree\n";
    print(root);
 
    reverseAlternate(root);
 
    cout << "\n\nInorder Traversal of modified tree\n";
    print(root);
    return 0;
}


