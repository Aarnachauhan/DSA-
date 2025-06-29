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

division operation method (not allowed for lc)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int pro=1;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                pro*=nums[i];
            }
            if(nums[i]==0) count++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(count>0) res[i]=0;
                else res[i]=pro/nums[i];
            }
            else{
                if(count>1) res[i]=0;
                else{
                    res[i]=pro;
                }
            }
        }
        return res;
    }
};

better
