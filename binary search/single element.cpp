class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        //first element 
        if(nums[0]!=nums[1]) return nums[0];
        //last element
        if(nums[n-2]!=nums[n-1]) return nums[n-1];
        int s=1;
        int e=n-2;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1] ) return nums[mid];
             //we are on the left and element is on the right (even,odd) (1,1)
             if(mid%2==1 && nums[mid-1]==nums[mid] || 
             mid%2==0 && nums[mid]==nums[mid+1] ){
                s=mid+1;
             }
             else{ //we are on right and element is on left half (odd,even) (1,1)
                e=mid-1;
             }
        }
        return -1;
    }
};
