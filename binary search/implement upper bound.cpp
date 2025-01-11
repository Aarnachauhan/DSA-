naukri.com
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int low=0;
        int n=arr.size();
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe the answer
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
