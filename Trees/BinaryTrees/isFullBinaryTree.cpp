bool isFullBinaryTree(Node *root){
	if(!root)return false;
	if(root->left==NULL && root->right==NULL)return true;
	
	if(root->left && root-?right){
		return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
	}
	
	return false;
}
