leetcode 53

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //int m=nums.size();
        int res=nums[0];
        int total=0;

        for(int n:nums){
            if(total<0){
               total=0;
            }
            total+=n;
            res=max(res,total);
        }
        return res;
    }
};
