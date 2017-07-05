#include<bits/stdc++.h>
using namespace std;

#define F(a,b,var) for(int var=a;var<b;var++)

int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int M,N;
            cin>>M>>N;
            int Mat[M][N];
            
            F(0,M,i){
                F(0,N,j){
                    cin>>Mat[i][j];
                }
            }
            int x;cin>>x;
            
            int i=0,j=N-1,res=0;
            
            while(i!=M && j>=0){
                if(Mat[i][j]>x)j--;
                else if(Mat[i][j]<x)i++;
                else{
                    res=1;break;
                }
            }
            if(res==1)cout<<1<<endl;
            else cout<<0<<endl;
            
            
        }
	return 0;
}
