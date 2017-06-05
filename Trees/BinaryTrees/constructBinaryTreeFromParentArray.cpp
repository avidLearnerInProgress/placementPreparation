#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(){
		val=0;
		left=right=NULL;
	}
};

Node* root=NULL; // pointer to a root
vector<Node> bt; // constructed binary tree

void buildBinaryTree(const vector<int>& parent)
{
    bt.resize(parent.size());
    for(int i=0; i<parent.size();i++)
    {
        if (parent[i]==-1)
            root=&bt[i];
        else if(bt[parent[i]].left==NULL)
            bt[parent[i]].left = &bt[i];
        else
            bt[parent[i]].right = &bt[i];
        bt[i].val = i;
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main(void)
{
    buildBinaryTree({ -1, 0, 0, 1, 1, 3, 5 });
    inorder(root);
}
