#include <iostream>
using namespace std;

void printspiral(int arr[101][101],int n)
{
    int left = 0, top=0, bottom = n, right= n, count=0;
    while( left<right&&top<bottom)
    {
        
        for(int i=left;i<right;i++)cout<<arr[top][i]<<" ";
        top++;
        for(int i = top;i<bottom;i++)cout<<arr[i][right-1]<<" ";
        right--;
        if(left<right)
        for(int i=right-1;i>=left;i--)cout<<arr[bottom-1][i]<<" ";
        bottom--;
        if(top<bottom)
        for(int i=bottom-1;i>=top;i--)cout<<arr[i][left]<<" ";
        left++;
    }
    cout<<endl;
}


int main() {
    
    int it, n=4, i, j, arr[101][101];
    cin>>it;
    while(it--)
    {

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>arr[i][j];
        
        printspiral( arr, 4);
    
    }
	return 0;
}
