#include<bits/stdc++.h>
using namespace std;

struct Activity{
	int start,finish;
};

bool activityCompare(Activity a,Activity b){
	return(a.finish<b.finish);
}


void activitySelectionProblem(Activity arr[],int n){
	
	sort(arr,arr+n,activityCompare);
	
	int i=0;
	cout<<"("<<arr[i].start<<","<<arr[i].finish<<")"<<endl;
	int count=1;
	for(int j=1;j<n;j++){
		
		if(arr[j].start>=arr[i].finish){
			
			cout<<"("<<arr[j].start<<","<<arr[j].finish<<")"<<endl;
			i=j;
			count++;
		}
	}
	cout<<count<<endl;
}



int main()
{
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
	activitySelectionProblem(arr, n);
    return 0;
}
