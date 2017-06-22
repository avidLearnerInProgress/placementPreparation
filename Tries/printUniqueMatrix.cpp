#include <bits/stdc++.h>
using namespace std;

#define F(a,b) for(int i=a;i<b;i++)

const int MAX = 100;
int mat[MAX][MAX];
 
 
void fillRemaining(int k,int j,int n){
	int x=2;
	
	F(k+1,n){
		mat[i][j]=x++;
	}
	
	F(0,k){
		mat[i][j]=x++;
	}
}
 
void constructMatrix(int n){
	
	int right=n-1;int left=0;
	F(0,n){
		
		if(i%2==0){
			mat[i][right]=1;
			fillRemaining(i,right,n);
			right--;
		}
		else{
			mat[i][left]=1;
			fillRemaining(i,left,n);
			left++;
		}
	}
}

int main()
{
    int n = 5;
 
    // Passing n to constructMatrix function
    constructMatrix(n);
 
    // Printing the desired unique matrix
	F(0,n)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

