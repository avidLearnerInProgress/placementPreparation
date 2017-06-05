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

void preorder(Node* root)
{
    if (root)
    {
        cout << "key: "<< root->data;
        if (root->left)
            cout << " | left child: " << root->left->data;
        if (root->right)
            cout << " | right child: " << root->right->data;
        cout << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void encodeSuccinct(Node *root,list<bool> &structure,list<int> &data){
	
	if(root==NULL){
		structure.push_back(0);
		return;
	}
	
	structure.push_back(1);
	data.push_back(root->data);
	encodeSuccinct(root->left,structure,data);
	encodeSuccinct(root->right,structure,data);
}

Node *decodeSuccinct(list<bool> &structure,list<int> &data){
	 if (structure.size() <= 0)
        return NULL;
 
	
	bool b=structure.front();
	structure.pop_front();
	
	if(b){
		int key=data.front();
		data.pop_front();
		
		Node *root=new Node(key);
		root->left=decodeSuccinct(structure,data);
		root->right=decodeSuccinct(structure,data);
		return root;
	}
	
	return NULL;
}

int main(){
	
	Node *root         = new Node(10);
    root->left         = new Node(20);
    root->right        = new Node(30);
    root->left->left   = new Node(40);
    root->left->right  = new Node(50);
    root->right->right = new Node(70);
 
    cout << "Given Tree\n";
    preorder(root);
    list<bool> structure;
    list<int>  data;
    encodeSuccinct(root, structure, data);
 
    cout << "\nEncoded Tree\n";
    cout << "Structure List\n";
    list<bool>::iterator si; // Structure iterator
    for (si = structure.begin(); si != structure.end(); ++si)
        cout << *si << " ";
 
    cout << "\nData List\n";
    list<int>::iterator di; // Data iIterator
    for (di = data.begin(); di != data.end(); ++di)
        cout << *di << " ";
 
    Node *newroot = decodeSuccinct(structure, data);
 
    cout << "\n\nPreorder traversal of decoded tree\n";
    preorder(newroot);
 
    return 0;
}


