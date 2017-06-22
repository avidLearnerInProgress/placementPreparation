#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 3
#define F(a,b,var) for(int var=a;var<b;var++)

struct Trie{
    Trie *children[26];
    bool isLeaf;
    
    Trie(){
        F(0,26,i)children[i]=NULL;
        isLeaf=false;
    }
};

Trie *root=NULL;

void insert(string s){
    
    Trie *node=root;
    F(0,s.length(),i){
        int index=(int)s[i]-(int)'A'; // could be a macro definition 
        if(node->children[index]==NULL)node->children[index]=new Trie();
        node=node->children[index];
    }
    node->isLeaf=true;
}

bool isSafe(int i,int j,bool visited[M][N]){
    return (i>=0 && i<M && j>=0 && j<N && !visited[i][j]);
}

void searchWord(Trie *node,char boggle[M][N],int i,int j,string res,bool visited[][N]){
    if(node->isLeaf)cout<<res<<endl;
    
    if(isSafe(i,j,visited)){
        visited[i][j]=true;
        F(0,26,k){
            if(node->children[k]!=NULL){
                
                
                char ch=(char)k + (char)'A';
                
                if(isSafe(i+1,j+1,visited)&& boggle[i+1][j+1]==ch)
                    searchWord(node->children[k],boggle,i+1,j+1,res+ch,visited);
                if(isSafe(i-1,j-1,visited)&& boggle[i-1][j-1]==ch)
                    searchWord(node->children[k],boggle,i-1,j-1,res+ch,visited);
                    
                if(isSafe(i,j+1,visited)&& boggle[i][j+1]==ch)
                    searchWord(node->children[k],boggle,i,j+1,res+ch,visited);
                if(isSafe(i,j-1,visited)&& boggle[i][j-1]==ch)
                    searchWord(node->children[k],boggle,i,j-1,res+ch,visited);
                    
                if(isSafe(i+1,j-1,visited)&& boggle[i+1][j-1]==ch)
                    searchWord(node->children[k],boggle,i+1,j-1,res+ch,visited);
                if(isSafe(i-1,j+1,visited)&& boggle[i-1][j+1]==ch)
                    searchWord(node->children[k],boggle,i-1,j+1,res+ch,visited);    
                
                if(isSafe(i+1,j,visited)&& boggle[i+1][j]==ch)
                    searchWord(node->children[k],boggle,i+1,j,res+ch,visited);
                if(isSafe(i-1,j,visited)&& boggle[i-1][j]==ch)
                    searchWord(node->children[k],boggle,i-1,j,res+ch,visited);    
            }
        }
        visited[i][j]=false;
    }
}

void findWords(char boggle[M][N]){
    
    Trie *node=root;
    bool visited[M][N];
    memset(visited,false,sizeof(visited));
    string res="";
    
    F(0,M,i){
        F(0,N,j){
            if(node->children[((int)boggle[i][j] - (int)'A')]){
                res+=boggle[i][j];
                searchWord(node->children[((int)boggle[i][j] - (int)'A')],boggle,i,j,res,visited);
                res="";
            }
        }
    }
    
}
int main()
{
    string dictionary[]={"GEEKS","FOR","QUIZ","GEE"};
    root=new Trie();
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    F(0,n,i)
        insert(dictionary[i]);
    char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}
                        };
    findWords(boggle);
    return 0;
}




/*http://ide.geeksforgeeks.org/oOoRS4*/

