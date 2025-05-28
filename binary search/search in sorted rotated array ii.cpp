class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target) return true;
            //edge cases
             if(nums[s]==nums[mid] && nums[mid]==nums[e]){
                s++;
                e--;
                continue;
             }

            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && nums[mid]>=target){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[e]>=target){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
            mid=(s+e)/2;
        }
        return false;
    }
};
