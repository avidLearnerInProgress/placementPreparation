void _build(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--) heapify(arr,n,i);
}

void heapify(int arr[], int n, int i)  {
      // Your Code Here
      int largest=i;
      int left=(2*i)+1;
      int right=(2*i)+2;
      
      if(left<n && arr[left]>arr[largest])largest=left;
      if(right<n && arr[right]>arr[largest])largest=right;
      
      if(largest!=i){
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,n,largest);
     }
}     

// Rearranges input array so that it becomes a min heap
void buildHeap(int arr[], int n){ 
    // Your Code Here
    _build(arr,n);
   //for(int i=(n/2)-1;i>=0;i--) heapify(arr,n,i);
}
