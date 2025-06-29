leetcode 238
brute force- give tle
tc-o(n2)
sc-o(1) (extra space for storing ans in array not for solving)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>  res;
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=0;j<n;j++){
                if(j!=i){
                    product*=nums[j];
                }
                else{
                    continue;
                }
                
            }
            res.push_back(product);
        }
        return res;
    }
};

brute:
