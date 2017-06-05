#include<bits/stdc++.h>
using namespace std;
#define MARKER -1
struct Node{
	int key;
	Node *left,*right;
	Node(int d){
		key=d;
		left=right=NULL;
	}
};

void serialize(Node *root, FILE *fp)
{
	
    if (!root){
        fprintf(fp, "%d ", MARKER);
        return;
    }
    fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}


void deSerialize(Node *&root, FILE *fp)
{
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;
    root = new Node(val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    
	Node *root        = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);
 
    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL)
    {
        puts("Could not open file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);
    Node *root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);
 
    printf("Inorder Traversal of the tree constructed from file:\n");
    inorder(root1);
 
    return 0;
}
