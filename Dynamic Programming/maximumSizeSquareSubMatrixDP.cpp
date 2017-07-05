#include<bits/stdc++.h>
using namespace std;

#define R 6
#define C 5

int maximumSizeSquare(int mat[][C]){
    
    int sub[R][C];
    
    for(int i=0;i<R;i++){
        sub[i][0]=mat[i][0];
    }
    
    for(int i=0;i<C;i++){
        sub[0][i]=mat[0][i];
    }
    
    for(int i=1;i<R;i++) // fill table
    {
        for(int j=1;j<C;j++){
            if(mat[i][j]==1)
                sub[i][j]=min(sub[i-1][j-1],min(sub[i][j-1],sub[i-1][j]))+1;
            else sub[i][j]=0;
        }
        
    }
    
    int max_sub=sub[0][0];  // find max
    int _i=0;
    int _j=0;
    
    for(int i=0;i<R;i++) 
    {
        for(int j=0;j<C;j++){
            if(max_sub<sub[i][j]){
                max_sub=sub[i][j];
                _i=i;
                _j=j;
            }
        }
    }
    //_i and _j needed to print matrix
    cout<<max_sub<<endl;
}

int main()
{
  int M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                
  maximumSizeSquare(M);
    return   0;
}  
