#include<bits/stdc++.h>
using namespace std;

int countPossiblePaths(int m,int n){
    int count[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
           if(i==0||j==0)count[i][j]=1;
            
           else count[i][j]=count[i-1][j]+count[i][j-1];
        }
    }
    return count[m-1][n-1];
}


int main(){
    cout<<countPossiblePaths(3,3)<<endl;
}
