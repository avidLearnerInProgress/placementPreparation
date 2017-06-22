//pattern searching algorithms .. naive algorithm

#include<bits/stdc++.h>
using namespace std;

void search(char *pat,char *txt){
    
    int N=strlen(txt);
    int M=strlen(pat);
    int i;
    for(i=0;i<=(N-M);i++){
        int j;
        for(j=0;j<M;j++)
            if(txt[i+j]!=pat[j])
                break;
        
        
        if(j==M)cout<<"Pattern Found At: "<<i<<endl;
    }
}

int main()
{
   char txt[] = "AABAACAADAABAAABAA";
   char pat[] = "AABA";
   search(pat, txt);
   //return 0;
}


