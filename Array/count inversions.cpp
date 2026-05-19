tc-o(n1) + o(n2)
sc-o(same as tc)

class Solution {
  public:
  int countandmerge(vector<int> &arr,int low, int m , int high){
      int n1=m-low+1 , n2=high-m;
      
      // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + low];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i 
      	// elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
  }
  int cntarr(vector<int> &arr, int low , int high){
      int res=0;
      if(low<high){
          int m=(low+high)/2;
          res+=cntarr(arr,low,m);
          res+=cntarr(arr,m+1,high);
          res+=countandmerge(arr,low,m,high);
      }
      return res;
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return cntarr(arr,0,n-1);
    }
};
