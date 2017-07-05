#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int countEndless(bool mat[][MAX],int n){
    
    bool row[n][n],col[n][n];
    bool isEndless;
    
    for(int j=0;j<n;j++){
        isEndless=1;
        for(int i=n-1;i>=0;i--){
            
            if(mat[i][j]==0){
                isEndless=0;
            }
            col[i][j]=isEndless;
        }
    }
    
    for(int j=0;j<n;j++){
        isEndless=1;
        for(int i=n-1;i>=0;i--){
            
            if(mat[i][j]==0){
                isEndless=0;
            }
            row[i][j]=isEndless;
        }
    }
    
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(row[i][j] && col[i][j])
            res++;
        }
    }
    
    
    cout<<res<<endl;
}


int main()
{
    bool input[][MAX] = { {1, 0, 1, 1},
                         {0, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    int n = 4;
    countEndless(input, n);
    return 0;
}
