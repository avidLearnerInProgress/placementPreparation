#include<bits/stdc++.h>
using namespace std;

#define n 4

struct heap{
	int element;
	int i,j;
};

bool operator>(const heap& lhs, const heap& rhs)
{
  return lhs.element > rhs.element;
}

void printSorted(int mat[][4]){
	
	priority_queue<heap,vector<heap>,greater<heap>> pq;
	
	for(int k=0;k<n;k++){
		heap h;
		h.element=mat[k][0];
		h.i=k;
		h.j=1;
		pq.push(h);
	}
	
	for(int k=0;k<n*n;k++){
		heap temp=pq.top();
		pq.pop();
		cout<<temp.element<<" ";
		if(temp.j<n){
			temp.element=mat[temp.i][temp.j];
			temp.j+=1;
		}
		else temp.element=INT_MAX;
		pq.push(temp);
	}
}

int main()
{
int mat[n][n] = { {10, 20, 30, 40},
					{15, 25, 35, 45},
					{27, 29, 37, 48},
					{32, 33, 39, 50},
				};
printSorted(mat);
return 0;
}
