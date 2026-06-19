leetcode 

tc-o(2^n * n) 
sc approx o(2^n * n) as not all subject will be of n length
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int mask=0;mask < ( 1 << n ) ; mask++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};    }
};
