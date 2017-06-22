#include<bits/stdc++.h>
using namespace std;

#define INT_SZ 32

#define F(var) for(var=INT_SZ-1;var>=0;var--)
#define F1(a,b,var) for(var=a;var<b;var++)

struct Trie{
	
	Trie *arr[2];
	int value;
	Trie(){
		
		arr[0]=arr[1]=NULL;
		value=0;
	}
	
};


Trie *root=NULL;

void insert(int a){
	Trie *node=root;
	int i;
	F(i){
		
		bool val=a&(1<<i);
		
		if(node->arr[val]==NULL)
			node->arr[val]=new Trie();
			
		node=node->arr[val];
		
	}
	
	node->value=a;
}


int query(int a){
	Trie *node=root;
	int i;
	F(i){
		bool val=a&(1<<i);
		
		if(node->arr[1-val]!=NULL)
			node=node->arr[1-val];
		
		else if(node->arr[val]!=NULL)
			node=node->arr[val];
	}
	return (a^node->value);
}


int maxSubarrayXOR(int arr[],int n){
	
	root=new Trie();
	insert(0);
	
	int result=INT_MIN;
	int temp=0;
	int i;
	F1(0,n,i){
		temp=temp^arr[i];
		insert(temp);
		result=max(result,query(temp));
	}
	return result;
}

int main()
{
    int arr[] = {8, 1, 2, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n);
    return 0;
}
