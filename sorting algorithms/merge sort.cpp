gfg
tc-n for merging 
and logn for dividing 
so tc-o(nlogn)
sc-o(logn) //recursion stack of space 

and if interview ask to ignore recursive stack space then sc-o(n) as we are using 2 vectors to store.
  

class Solution {
  public:
  void merge(vector<int> &arr,int l , int mid, int r){
      vector<int> temp;
      int left=l , right=mid+1;
      while(left<=mid && right<=r){
          if(arr[left]<=arr[right]){
              temp.push_back(arr[left]);
              left++;
          }
          else{
              temp.push_back(arr[right]);
              right++;
          }
      }
      
      while(left<=mid) temp.push_back(arr[left++]);
      while(right<=r)  temp.push_back(arr[right++]);
      
      for (int i = l; i <= r; i++)
            arr[i] = temp[i - l];
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};
