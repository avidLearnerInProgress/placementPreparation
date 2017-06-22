#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000
#include<string.h>
// you are required to complete this function 
// function should print the required range
void findSmallestRange(int arr[][N], int n, int k)
{
      //code here
      int A[k];
      memset(A,0,sizeof(A));
      int start = 0;
      int end = 0;
      int range = 99999;
      
      while(1){
          int min_index,max_index;
          int min = 99999;
          int max = -99999;
          
          for(int j = 0; j<k; j++){
              if(min > arr[j][A[j]]){
                  min  = arr[j][A[j]];
                  min_index = j;
                  
              }
              if(max < arr[j][A[j]]){
                  max = arr[j][A[j]];
                  max_index = j;
                  
              }
          }
          if(range > (max - min)){
              range = max - min;
              start = min;
              end = max;
          }
          if(A[min_index] < n - 1){
              A[min_index]++;
          }
          else{
              cout<<start<<" "<<end<<endl;
              return ;
          }
      }
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}


