#include <bits/stdc++.h>
using namespace std;

//Program for min cost !

#define R 3
#define C 3

int minCostToReach(int mat[][C],int m,int n){
    
    int tc[R][C];
    
    tc[0][0]=mat[0][0];
    
    for(int i=1;i<=R;i++){
        tc[i][0]=tc[i-1][0]+mat[i][0];
    }
    
    for(int i=1;i<=C;i++){
        tc[0][i]=tc[0][i-1]+mat[0][i];
    }
    
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            tc[i][j]=min(tc[i-1][j-1],min(tc[i][j-1],tc[i-1][j]))+mat[i][j];
        }
    }
    return tc[m][n];
}


int main() {
	//code
	 int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
    cout<<minCostToReach(cost,2,2);
	
	return 0;
}
