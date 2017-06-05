#include<bits/stdc++.h>
using namespace std;

#define n 4

struct heap{
	int i;
	int j;
	int element;
	
};

bool operator>(const heap& a,const heap& b){
	return a.element>b.element;
}

void printSorted(int mat[][n],int k){
	
	priority_queue<heap,vector<heap>,greater<heap>> pq;
	heap h;
	for(int l=0;l<k;l++){
		
		h.element=mat[l][0];
		h.i=l;
		h.j=0;
		pq.push(h);
	}
	
	while(!pq.empty()){
		h=pq.top();
		pq.pop();
		
		cout<<h.element<<" ";
		if(h.j!=n-1){
			heap temp;
			temp.element=mat[h.i][h.j+1];
			temp.i=h.i;
			temp.j=h.j+1;
			pq.push(temp);
		}
	}
	
}

/*Simpler Solution
int *mergeKArrays(int arr[][N], int k) {
    //code here
    int n = k*k;
    vector<int> v;
    for(int i = 0; i < k; i++) for(int j = 0; j <k ; j++) v.push_back(arr[i][j]);
    sort(v.begin(), v.end());
    int *ans = new int[k*k];
    //ans = new int[k*k];
    for(int i = 0; i < n; i++) ans[i] = v[i];
    return  ans;
}
*/

int main() {
 
	int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
	int k = sizeof(arr)/sizeof(arr[0]);
	printSorted(arr,k);
 
  	return 0;
}
