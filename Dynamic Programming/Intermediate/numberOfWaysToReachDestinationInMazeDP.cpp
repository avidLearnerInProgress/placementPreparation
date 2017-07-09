#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define ll long long int 


ll cnt(int mat[][1000],int n,int m){
    
    if(mat[0][0]==-1)return 0;
    mat[0][0]=1;
   /* 
    for(int i=0;i<n;i++){
        if(mat[i][0]==0)
        mat[i][0]=1;
        else break;
    }
    
    for(int i=1;i<m;i++){
        if(mat[0][i]==0)
        mat[0][i]=1;
        else break;
    }
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(mat[i][j]==-1)continue;
            
            if(i-1>=0 && mat[i-1][j]>0){
                mat[i][j]=mat[i-1][j]%mod;
            }
            
            if(j-1>=0 && mat[i][j-1]>0){
               mat[i][j]=((mat[i][j]%mod)+(mat[i][j-1]%mod))%mod;
            }
        }
    }
    
    return (mat[n-1][m-1]>0)?(mat[n-1][m-1]%mod):0;
}


int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        {   
            int n,m,k;
            cin>>n>>m>>k;
            int mat[1000][1000];
            memset(mat,0,sizeof(mat));
            int a,b;
            int setblocked=k;
            while(setblocked--){
                cin>>a>>b;
                mat[a-1][b-1]=-1;
            }
            ll  x=cnt(mat,n,m);
            cout<<x<<endl;
        }       
	return 0;
}
