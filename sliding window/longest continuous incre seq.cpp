tc-o(n)
sc=o(1)
leetcode 674
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int maxi=1;
        int cnt=1;
        while(j<n){
          if(nums[j]>nums[j-1]){
            maxi=max(j-i+1,maxi);
            j++;
          }
          else {
            i=j;
            j++;
          }
        }
        return maxi;
    }
};
