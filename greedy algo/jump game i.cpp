lc 55
tc-o(n)
sc-o(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          if(i>maxind) return false;
          else maxind=max(maxind,nums[i]+i);
        }
        return true;
    }
};
  
