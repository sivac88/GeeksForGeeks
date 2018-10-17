//https://practice.geeksforgeeks.org/problems/minimum-swaps/1
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minSwaps(int arr[], int n){
    
     int i, j, min_idx,ans=0; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
     
        if(min_idx!=i)
        {
         ans++;  
         swap(&arr[min_idx], &arr[i]); 
        }
    } 
    
    return ans;
}]