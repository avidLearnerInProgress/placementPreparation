#include<bits/stdc++.h>
using namespace std;

void printLCS(string &x,string &y){
    
    int m=x.length();
    int n=y.length();
    int LCS[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                LCS[i][j]=0;
            else if(x[i-1]==y[j-1])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    
    int index=LCS[m][n];
    
    char lcs[index+1];
    lcs[index]='\0';
    
    int i=m,j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            lcs[index-1]=x[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCS[i-1][j]>LCS[i][j-1])i--;
        else j--;
        
        
    }
    cout<<"LCS:"<<lcs<<endl;
    return;
}


int __lcs(string &x,string &y){
    
    int m=x.length();
    int n=y.length();
    int LCS[2][n+1];
    bool bi;
    for(int i=0;i<=m;i++){
          bi=i&1;
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                LCS[bi][j]=0;
            else if(x[i]==y[j])
                LCS[bi][j]=LCS[1-bi][j-1]+1;    //value of bi will be either 1 or 0 so at a time atmost 2 rows are stored row 0 and row 1
            else
                LCS[bi][j]=max(LCS[1-bi][j],LCS[bi][j-1]);
        }
    }
    
    return LCS[bi][n];
}

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int m,n;
            cin>>m>>n;
            
            string a;
            cin>>a;
            string b;
            cin>>b;
            
            printLCS(a,b);
            
            int res=__lcs(a,b);
            cout<<res<<endl;
        }
	return 0;
}

/*1
6 7
AGGTAB
GXTXAYB
*/
