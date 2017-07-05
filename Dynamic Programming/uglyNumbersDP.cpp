#include<bits/stdc++.h>
using namespace std;


int uglyNumbers(int n){
    
    int ugly[n];
    
    int i2,i3,i5;
    i2=i3=i5=0;
    int n2,n3,n5;
    n2=2;
    n3=3;
    n5=5;
    ugly[0]=1;
    int nugly;
    
    for(int i=1;i<n;i++){
        
        nugly=min(n2,min(n3,n5));
        ugly[i]=nugly;
        
        if(nugly==n2){
            i2=i2+1;
            n2=ugly[i2]*2;
        }
        
        if(nugly==n3){
            i3=i3+1;
            n3=ugly[i3]*3;
        }
        
        if(nugly==n5){
            i5=i5+1;
            n5=ugly[i5]*5;
        }
        
    }
    
    return nugly;
}


int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        { 
            int n;cin>>n;
            int res=uglyNumbers(n);
            cout<<res<<endl;
        }
	return 0;
}
