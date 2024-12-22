tc-o(2*logn)
  sc-O(1)
class Solution {
public:
int lowerBound(vector<int>& nums, int target) {
        // code here
        int n=nums.size();
        int low=0;
        int high=nums.size()-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe it is the answer
            if(nums[mid]>=target){
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
     int upperBound(vector<int>& nums, int target) {
        // code here
        int low=0;
        int n=nums.size();
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe the answer
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerBound(nums,target);
        if(lb==n) return {-1,-1};
        if(nums[lb]!=target) return {-1,-1};
        return{lb,upperBound(nums,target)-1};
    }
};
