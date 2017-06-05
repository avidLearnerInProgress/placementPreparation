#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node * left;
	struct node * right;
};

struct node * newnode(int key){
	struct node *newN=(struct node * )malloc(sizeof(struct node));
	newN->key=key;
	newN->left=NULL;
	newN->right=NULL;
	return newN;
}

int level(struct node *root,int i)
{	
	static int sum;
	if(i==0 || root==NULL)
		return 0;
	level(root->left,i-1);
	level(root->right,i-1);
	if(root->left==NULL && root->right==NULL&& i==1)
		sum+=root->key;
	return sum;
}
int levelsum(struct node *root,int ht)
{
	int i,mul=1;
	 int array[ht];
	 array[0]=0;
	for(i=1;i<=ht;i++)
	{
		array[i]=level(root,i);
	}
	for(i=ht;i>=1;i--)
	{
		array[i]=array[i]-array[i-1];
		if(array[i]>0)
			mul*=array[i];
		
	}
	
	
	return mul;
} 
 
int max(int left,int right) 
{
	if(left>right)
		return left;
	else
		return right;	
}
int findht(struct node * root)
{
	if(root==NULL)
		return 0;
	return(max(findht(root->left),findht(root->right))+1); 
}

int main()
{
	struct node *root = newnode(2);
    root->left = newnode(7);
    root->right = newnode(5);
    root->left->right = newnode(6);
    root->left->left = newnode(8);
    root->left->right->left = newnode(1);
    root->left->right->right = newnode(11);
    root->right->right = newnode(9);
    root->right->right->left = newnode(4);
    root->right->right->right = newnode(10);
	int ht=findht(root);
	int mul=levelsum(root,ht);
	printf("%d",mul);

}	
