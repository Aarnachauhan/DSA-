leetcode 164
tc-o(nlogn)
sc-o(1)

class Solution {
public:
    int maximumGap(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       if(n<2) return 0;
       int maxi=INT_MIN;
       for(int i=1;i<n;i++){
        maxi=max(maxi, nums[i]-nums[i-1]);
       }
       return maxi;
    }
};
