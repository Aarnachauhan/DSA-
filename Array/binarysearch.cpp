class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {
          int n=arr.size();
        int l=0;
        int h=n-1;
      
        while(l<=h){
            int m = l + (h - l) / 2;
            if(arr[m]==k) return true;
            else if(k>arr[m]){
                l=m+1;
            }
            else h=m-1;
        }
        return false;
    }
     
};
