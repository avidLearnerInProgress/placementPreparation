
#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void TOWUtil(int *arr,int n,bool curr_elements[],bool sol[],int *min_diff,int sum,int no_of_selected_elements,int curr_sum,int curr_position){
	
	if(curr_position==n)return;

	if((n/2-no_of_selected_elements)>n-curr_position)return;

	TOWUtil(arr,n,curr_elements,sol,min_diff,sum,no_of_selected_elements,curr_sum,curr_position+1);

	no_of_selected_elements++;
	curr_sum+=arr[curr_position];
	curr_elements[curr_position]=true;

	if(no_of_selected_elements==n/2){
		if(abs(sum/2 - curr_sum )< *min_diff){
			*min_diff=abs(sum/2 - curr_sum);
			for(int i=0;i<n;i++)sol[i]=curr_elements[i];
		}
	}
	else{
		TOWUtil(arr,n,curr_elements,sol,min_diff,sum,no_of_selected_elements,curr_sum,curr_position+1);	
	}	
	curr_elements[curr_position]=false;	
}




void tugOfWar(int *arr,int n){
	
	bool *curr_elements=new bool[n];
	bool *sol=new bool[n];
	int min_diff=INT_MAX;
	int sum=0;

	for(int i=0;i<n;i++){
		sum+=arr[i];
		curr_elements[i]=sol[i]=false;

	}

	TOWUtil(arr,n,curr_elements,sol,&min_diff,sum,0,0,0);

	for(int i=0;i<n;i++){
	if(sol[i]==true)cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
	if(sol[i]==false)cout<<arr[i]<<" ";
	}

}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}

