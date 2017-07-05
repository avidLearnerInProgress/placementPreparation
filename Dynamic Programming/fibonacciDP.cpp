#include<bits/stdc++.h>
using namespace std;



int fibonacci(int n){
//Recursive    
    if(n==0)return 0;
    if(n==1)return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int _fibonacci(int n){
//Non-Recursive    
    int a=0,b=1;
    if(n==0)return a;
    
    for(int i=2;i<=n;i++){
        int temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}

int __fibonacci(int n,int hash[]){
   //DP 
    hash[0]=0;
    hash[1]=1;
    
    if(hash[n]!=-1)return hash[n];
    hash[n]=__fibonacci(n-1,hash)+__fibonacci(n-2,hash);
    return hash[n];
}


int main(){
    
    int n=10;
    int result=fibonacci(n);
    int _result=_fibonacci(n);
    
    int hash[n+1];
    memset(hash,-1,sizeof(hash)+1);
    int __result=__fibonacci(n,hash);
    
    cout<<result<<_result<<__result<<endl;
}
