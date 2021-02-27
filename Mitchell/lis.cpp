//returns the longest increasing subsequence in arr[]
int lis( int arr[], int n ){
    int lis[n]; 
    lis[0] = 1;
  
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    return *max_element(lis, lis+n); 
}  
