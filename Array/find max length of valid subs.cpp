leetcode 3201 
tc-o(n)
sc-o(1)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int ceven=0;
        int codd=0;
        int alt=1; //length of starting parity
        for(int &num: nums){
            if(num%2==0) ceven++;
            else codd++;
        }
        int parity=nums[0]%2;
        for(int i=1;i<n;i++){
            int curparity=nums[i]%2;
          if(curparity!=parity){
            alt++;
            parity=curparity;
          }
        }
      return max({ceven ,codd, alt});
    }
};
