leetcode 

tc-o(2^n * n) 
sc approx o(2^n * n) as not all subject will be of n length
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int total=pow(2,n)-1;

        vector<vector<int>>ans;
        for(int i=0;i<=total;i++){ //2^n
            vector<int> sub;
            for(int j=0;j<n;j++){ //n
                if(i&(1<<j)) sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
