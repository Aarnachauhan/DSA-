leetcode
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int h=n-1;
        int ans=INT_MAX;
        while(s<=h){
            int mid=(s+h)/2;
          if(nums[s]<=nums[mid]){
            ans=min(ans,nums[s]);
            s=mid+1;
          }
          else{
            ans=min(nums[mid],ans);
            h=mid-1;
          }
        }
        return ans;
    }
};
