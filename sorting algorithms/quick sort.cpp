gfg
tc-o(nlogn)
sc-o(n)
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int partindex=partition(arr,low,high);
            quickSort(arr,low,partindex-1);
            quickSort(arr,partindex+1,high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(arr[i]<=pivot && i<=high){
                i++;
            }
            while(arr[j]>pivot&& j>=low) j--;
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
        
    }
};
