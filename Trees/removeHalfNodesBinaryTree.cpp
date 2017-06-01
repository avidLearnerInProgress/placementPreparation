Node *removeHalfNodes(Node *root){
	if(root==NULL)return NULL;
	
	root->left=removeHalfNodes(root->left);
	root->right=removeHalfNodes(root->right);
	if(root->left==NULL && root->right==NULL)return root;
	
	if(root->left==NULL){
		Node *temp=root->right;
		free(root);
		return temp;
	}
	
	if(root->right==NULL){
		Node *temp=root->left;
		free(root);
		return temp;
	}
	return root;
}
