
/*
We can solve this problem in O(nlogk)
using a min heap. The idea is to
construct a min-heap of size k+1 and
insert k+1 elements into the heap.
Then we remove min from the heap and
insert next element from the array into
the heap and and continue the process
till both array and heap is exhausted.
Each pop operation from the heap should
insert the corresponding top element in
its correct position in the array.
*/

#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)cout<<arr[i]<<" ";
return;	
}

void nearlySorted(int arr[],int n,int k){
	
	std::priority_queue<int,vector<int>,greater<int>> pq;
	int i,j;
	for(j=0;j<k;j++)pq.push(arr[j]);
	
	for(i=0;i<n;i++){
		arr[i]=pq.top();
		pq.pop();
		if(j<n){
			pq.push(arr[j]);
			j++;
		}
	}
}


int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    nearlySorted(arr, n, k);
 
    cout << "Following is sorted array\n";
    printArray (arr, n);
 
    return 0;
}


