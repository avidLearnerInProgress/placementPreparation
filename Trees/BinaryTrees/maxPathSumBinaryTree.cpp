#include<bits/stdc++.h>
using namespace std;
 
struct node 
{	
    int data;
    struct node* left, *right;
};
typedef struct node* Node;
typedef struct node node;
 
Node newNode(int data)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data  = data;
    temp->left  = temp->right = NULL;
    return(temp);
}
 
bool isleaf(Node root) { return root->left == NULL && root->right == NULL; }
 
int solve1(Node root, int &res) {
 
	if(!root) return 0;
	if(isleaf(root)) return root->data;
 
	int l = solve1(root->left, res);
	int r = solve1(root->right, res);
 
	// Try all possible combinations for optimal result
	res = max(res, l + root->data); 
	res = max(res, r + root->data);
	res = max(res, l + r + root->data);
	res = max(res, root->data);
 
	// return maximum of all possible paths 
	return max(root->data, max(l + root->data, r + root->data));	
}
 
 
void solve(Node &root) {
 
	int ans = 0;
	solve1(root, ans);
	cout << ans << endl;
} 
 
int main() {
 
// Let us construct the BST shown in the above figure
    Node root  		  = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
 
	solve(root);
    return 0;
}
