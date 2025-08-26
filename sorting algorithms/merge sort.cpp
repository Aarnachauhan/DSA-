gfg
tc-n for merging 
and logn for dividing 
so tc-o(nlogn)
sc-o(logn) //recursion stack of space 

and if interview ask to ignore recursive stack space then sc-o(n) as we are using 2 vectors to store.
  

  class Solution {
  public:
  void merge(vector<int> &arr , int l , int mid , int r){
      int n1=mid-l+1;
      int n2= r-mid; //( right - (mid +1 ) -1) -> right - mid
      vector<int> L(n1) , R(n2);
      for(int i=0;i<n1;i++){
          L[i]= arr[l+i];
      }
      for(int j=0;j<n2;j++){
          R[j]=arr[mid+1+j];
      }
      int i=0 , j=0 , k=l;
      
      while(i<n1 && j < n2){
          if(L[i]<=R[j]){
              arr[k]=L[i];
              i++;
          }
          else {
              arr[k]=R[j];
              j++;
          }
          k++;
      }
      
      while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return; // only one element is left.
        int mid=(l+r)/2;
        mergeSort(arr, l , mid);
        mergeSort(arr, mid+1 , r);
        merge(arr, l , mid , r);
        
    }
};
