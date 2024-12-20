class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target>nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
      // we are returning low because if we return high, pos will be -1.(0-1=-1) 
      //low will just increment.
        return low;
    }

};
