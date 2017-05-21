#include<iostream>
using namespace std;



void permute(int *arr, int s, int e, int idx, char *str)
{
	if(s==e) {
		str[idx] = '\0';
		cout << str << endl;
	   	return;
	}       
 
	int temp=0;
	for(int i=s; i<e && i<s+2; i++) {    
	    temp = (temp*10) + arr[i];    
	    if(temp <= 26) {
	        str[idx] = temp + ('a' - 1);
	    	permute(arr, i+1, e, idx+1, str);
	    }
	}
}

int main()
{
    int arr[20];
    char str[20];
    int n = 3;
    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 1;
    permute(arr,0,n,0,str);
}

