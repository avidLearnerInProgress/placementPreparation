#include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 

class minHeap{
	int heap_size;
	int capacity;
	int *heapArr;
	
	public:
	
	minHeap(int x){
		heap_size=0;
		capacity=x;
		heapArr=new int[capacity];
	}
	
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	int getMin();
	void insertKey(int k);
	void decreaseKey(int i,int k);
	int extractMin();
	void deleteKey(int i);
	void minHeapify(int i);
	
};

int minHeap::parent(int i){return (i-1)/2;}

int minHeap::leftChild(int i){return (i*2)+1;}
int minHeap::rightChild(int i){return (i*2)+2;}

int minHeap::getMin(){return heapArr[0];}

void minHeap::insertKey(int k){
	if(heap_size==capacity){
		cout<<"OverFlow"<<endl;
	}
	
	heap_size++;
	int i=heap_size-1;
	heapArr[i]=k;
	
	while(i!=0 && heapArr[parent(i)]>heapArr[i]){
		swap(&heapArr[i],&heapArr[parent(i)]);
		i--;
	}
}

void minHeap::decreaseKey(int i,int k){
	
	heapArr[i]=k;
	while(i!=0 && heapArr[parent(i)]>heapArr[i]){
		swap(&heapArr[i],&heapArr[parent(i)]);
		i--;
	}
}


int minHeap::extractMin(){
	if(heap_size<=0)return INT_MIN;
	if(heap_size==1){
		heap_size--;
		return heapArr[0];
	}
	int root=heapArr[0];
	heapArr[0]=heapArr[heap_size-1];
	heap_size--;
	
	minHeapify(0);
}


void minHeap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMin();
}


void minHeap::minHeapify(int i){
	int l=leftChild(i);
	int r=rightChild(i);
	int smallest=i;
	
	if(l<heap_size && heapArr[l]<heapArr[i])smallest=l;
	if(r<heap_size && heapArr[r]<heapArr[smallest])smallest=r;
	if(smallest!=i){
		swap(&heapArr[smallest],&heapArr[i]);
		minHeapify(smallest);
	}
}



// Driver program to test above functions
int main()
{
    minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
