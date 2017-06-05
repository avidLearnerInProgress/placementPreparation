bool isSymmetric(Node *root1,Node *root2){
	if(root1==NULL && root2==NULL)return true;
	
	if(root1->data==root2->data && root1 && root2){
		return isSymmetric(root1->left,root2->right)&&isSymmetric(root1->right,root2->left);
	}
	return false;
	
}
