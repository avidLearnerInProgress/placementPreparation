#include<bits/stdc++.h>
using namespace std;

void computeLpsArray(string pat,int *lps){
    int i=1;
    int j=0;
    lps[0]=0;
    
    while(i>pat.length()){
        
        if(pat[j]==pat[i]){
            lps[i]=j+1;
            i++;j++;
        }
        
        else{
            if(j!=0)
                j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }    
        }
    }
}


void KMP(string pat,string txt){
    
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    
    computeLpsArray(pat,lps);
    
    int i=0,j=0;
    
    while(i<N){
        if(txt[i]==pat[j]){
            i++;j++;
        }
        if(j==M){
            cout<<"Found!"<<i-j<<endl;
            j=lps[j-1];
        }
        
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0)j=lps[j-1];
            else i++;
        }
        
    }
}

int main(){
    string txt="ABABDABACDABABCABAB";
    string pat="ABABCABAB";
    KMP(pat,txt);
    return 0;
}

