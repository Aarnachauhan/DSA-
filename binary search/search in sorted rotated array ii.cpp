class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]==target) return true;
        //edge cases
        if(nums[s]==nums[mid] && nums[mid]==nums[e]) {
            s++;
            e--;
            continue;
        }
        if(nums[s]<=nums[mid]){ //left part is sorted
           if(nums[s]<=target && target<=nums[mid]){
            e=mid-1;
           }else{
            s=mid+1;
           }
        }else{ //right part is sorted
          if(nums[mid]<=target && target<= nums[e]){
            s=mid+1;
          }else{
            e=mid-1;
          }
        }
        }
       return false;
    }
};
