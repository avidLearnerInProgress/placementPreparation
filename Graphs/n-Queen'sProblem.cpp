#include<bits/stdc++.h>
using namespace std;

int board[1000][1000];
int n;

bool isSafe(int row,int col){
    int i,j;
    i=row;
    for(j=1;j<=col;j++)
        if(board[i][j])
            return false;

    for(i=row,j=col;i>=1 && j>=1;i--,j--)  //upper diagonal
    {
        if(board[i][j])
            return false;
    }
    for(i=row,j=col;i<=n && j>=1;i++,j--)  //lower diagonal
    {
        if(board[i][j])
            return false;
    }
    
    return true;
}


void nqueen(vector<int> &v,int n,int col,vector<vector<int> > &sol){
    
    if(col>n){
        sol.push_back(v);
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(isSafe(i,col)){
            board[i][col]=1;
            v.push_back(i);
            nqueen(v,n,col+1,sol);
            board[i][col]=0;
            v.pop_back();
        }
    }
    return;
}



int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            cin>>n;
            vector<int> v;
            vector<vector<int> > sol;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    board[i][j]=0;
                    
            nqueen(v,n,1,sol);
            if(sol.size()>0){
                for(int i=0;i<sol.size();i++){
                    cout<<"[";
                    for(int j=0;j<n;j++)
                        cout<<sol[i][j]<<" ";
                    cout<<"]"<<" ";
                }
                cout<<endl;
            }
            else cout<<-1<<endl;
        }
        return 0;
}
