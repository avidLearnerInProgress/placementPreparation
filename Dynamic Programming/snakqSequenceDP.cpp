#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 4

struct Point{
    int x,y;
};


list<Point> findAllPaths(int lookup[M][N],int i,int j){
  
  list<Point> path;
  Point p={i,j};
  path.push_front(p);
  
  while(lookup[i][j]!=0){
      
      if(i>0 && abs(lookup[i-1][j]-lookup[i][j])==1){
          p={i-1,j};
          path.push_front(p);
          i--;
      }
      
      if(j>0 && abs(lookup[i][j-1]-lookup[i][j])==1){
          p={i,j-1};
          path.push_front(p);
          j--;
      }
  }
  return path;
}

int snakeSeq(int mat[M][N]){
    
    int find[M][N];
    memset(find,0,sizeof(find));
    int maxEle=0;
    int maxR=0;
    int maxC=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            
            if(i||j){
                
                if(i>0 && abs(mat[i][j]-mat[i-1][j])==1){
                    find[i][j]=max(find[i][j],find[i-1][j]+1);
                    
                    if(maxEle<find[i][j]){
                        maxEle=find[i][j];
                        maxR=i;
                        maxC=j;
                    }
                }
                
                if(j>0 && abs(mat[i][j]-mat[i][j-1])==1){
                    find[i][j]=max(find[i][j],find[i][j-1]+1);
                    
                    if(maxEle<find[i][j]){
                        maxEle=find[i][j];
                        maxR=i;
                        maxC=j;
                    }
                }
            }
        }
    }
    cout<<maxEle<<endl;
    
    list<Point> paths=findAllPaths(find,maxR,maxC);
    
    for(auto it=paths.begin();it!=paths.end();it++){
         cout << endl << mat[it->x][it->y] << " (" << it->x << ", " << it->y << ")" ;
    }
}


int main()
{
    int mat[M][N] =
    {
        {9, 6, 5, 2},
        {8, 7, 6, 5},
        {7, 3, 1, 6},
        {1, 1, 1, 7},
    };
 
    snakeSeq(mat);
 
    return 0;
}
