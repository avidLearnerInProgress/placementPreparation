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

bool countSingleRec(Node *root,int &count){
	
	if(!root)return true;
	
	bool left=countSingleRec(root->left,count);
	bool right=countSingleRec(root->right,count);
	
	if(!left || !right)return false;
	
	if(root->left && root->data != root->left->data)return false;
	if(root->right && root->data != root->right->data)return false;
	
	count++;
	return true;
	
}

int countSingle(Node *root){
	int count=0;
	countSingleRec(root,count);
		return count;
	
}


int main()
{
    /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
     4    4      5 */
    Node* root        = new Node(5);
    root->left        = new Node(4);
    root->right       = new Node(5);
    root->left->left  = new Node(4);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
 
    cout << "Count of Single Valued Subtrees is "
         << countSingle(root);
    return 0;
}


