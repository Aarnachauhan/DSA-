leetcode713
tc-o(n2)
sc-o(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int pro=1;
        int cnt=0;
        for(int i=0;i<n;i++){
              sum=1;
            for(int j=i;j<n;j++){
                pro*=nums[j];
                if(pro<k) cnt++;
                else break;
            }    
        }
        return cnt;

    }
};

optimal
