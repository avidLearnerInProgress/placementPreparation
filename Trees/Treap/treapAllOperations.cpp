#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	int priority;
	
};

Node *newNode(int k){
	Node *temp=new Node;
	temp->data=k;
	temp->left=temp->right=NULL;
	temp->priority=rand()%100;
	return temp;
}

//Left - Left
Node *leftRotate(Node *x)
{
    Node *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;
    return y;
}
Node *rightRotate(Node *y)
{
    Node *x = y->left,  *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}


Node *search(Node *root,int key){
	if(root==NULL || root->data==key )return root;
	
	if(key<root->data)
	return search(root->left,key);
	
	if(key>root->data)
	return search(root->right,key);
	
}


Node *insert(Node *root,int key){
	if(root==NULL)return newNode(key);
	if(key<root->data){
		root->left=insert(root->left,key);
		if(root->left->priority>root->priority)
		root=rightRotate(root);
	}
	if(key>root->data){
		root->right=insert(root->right,key);
		if(root->right->priority>root->priority)
			root=leftRotate(root);
	}
	return root;
}

Node *deleteN(Node *root,int key){
	if(root==NULL)return root;
	if(key<root->data)root->left=deleteN(root->left,key);
	else if(key>root->data)root->right=deleteN(root->right,key);
	
	else if(root->left==NULL){
		Node *temp=root->right;
		delete(root);
		root=temp;
	}
	else if(root->right==NULL){
		Node *temp=root->left;
		delete(root);
		root=temp;
	}
	
	else if(root->left->priority<root->right->priority){
		root=leftRotate(root);
		root->left=deleteN(root->left,key);
		
	}
	
	else{
		root=rightRotate(root);
		root->right=deleteN(root->right,key);
	}
	
	return root;
	
}

void inorder(Node* root)
{
    if (root)
    {
        inorder(root->left);
        cout << "key: "<< root->data << " | priority: %d "
            << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->data;
        if (root->right)
            cout << " | right child: " << root->right->data;
        cout << endl;
        inorder(root->right);
    }
}
 
 
// Driver Program to test above functions
int main()
{
    srand(time(NULL));
 
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
 
    cout << "\nDelete 20\n";
    root = deleteN(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root = deleteN(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 50\n";
    root = deleteN(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 /*
   Node *res = search(root, 50);
    (res == NULL)? cout << "\n50 Not Found ":
                   cout << "\n50 found";
 
   */ return 0;
}
