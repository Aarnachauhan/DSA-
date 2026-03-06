lc 1752
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<=n-2;i++){
            if(nums[i-1]<nums[i] && nums[i+1]<nums[i]) cnt++;

        }
        if(cnt==0) return true;

        if(cnt==1 && nums[0]>nums[n-1]) return true;
        else return false;
    }
};
