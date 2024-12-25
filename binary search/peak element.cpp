class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int s=1;
        int e=n-2;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            //there is a greater peak at the right
            else if(nums[mid]>nums[mid-1]) s=mid+1 ; 
            //there is greater peak on the left
            else if(nums[mid]>nums[mid+1]) e=mid-1;
            //this is for multiple peaks, kahi bhi chale jao , peak mil hi jayegi
            else e=mid-1;
        }
        return -1;
    }
};
