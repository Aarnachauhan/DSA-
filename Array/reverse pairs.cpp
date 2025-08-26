leetcode 493
tc-o(n2)
sc-o(1)
brute code done by me!
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              if(nums[i] > (long long)2*nums[j]) cnt++;
            }
        }
        return cnt;
    }
};

optimal approach
