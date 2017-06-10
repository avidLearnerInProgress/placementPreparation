/*http://ideone.com/g7tw2L*/ /*- O(n) solution*/


#include<bits/stdc++.h>
using namespace std;
#define END '\0'
struct node{
	int freq;
	char c;
	node *left,*right;
	node(char x,int f){
		c=x;
		freq=f;
		left=right=NULL;
	}
};


class compare
{
public:
    bool operator() (node *a,node *b)
    {
        return a->freq>b->freq;
    }
};


void print_heap(node *head,string s){
	if(!head)return;
	if(head->c != END){
		cout<<head->c<<" code is: "<<s<<endl;
		
	}
	
	print_heap(head->left,s+"0");
	print_heap(head->right,s+"1");
	
}


int main(){
	
	priority_queue<node *,vector<node *>,compare> min_heap;
	
	min_heap.push(new node('a',5));
	min_heap.push(new node('b',9));
	min_heap.push(new node('c',12));
	min_heap.push(new node('d',13));
	min_heap.push(new node('e',16));
	min_heap.push(new node('f',45));
	
	while(min_heap.size()>1){
		node *min1=min_heap.top();
		min_heap.pop();
		node *min2=min_heap.top();
		min_heap.pop();
		
		node *newNode=new node(END,min1->freq+min2->freq);
		newNode->left=min1;
		newNode->right=min2;
		
		min_heap.push(newNode);
	}
	print_heap(min_heap.top(),string(""));
	return 0;
}

