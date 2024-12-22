class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int low=0;
        int high=arr.size()-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe it is the answer
            if(arr[mid]>=target){
                ans=mid;
                //look for small index on the left
                high=mid-1;
            }
            else{
                low=mid+1;//look on right;
            }
        }
        return ans;
    }
};
