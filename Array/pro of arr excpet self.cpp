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

better: extra space
tc-o(n)
sc-o(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> left(n),right(n);
        left[0]=1;
        //left
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
        }
        right[n-1]=1;
        //right
        for(int i=n-2;i>=0;i--){
            right[i]=nums[i+1]*right[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};


optimal :
tc-o(n)
sc-o(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        res[0]=1;

        for(int i=1;i<n;i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            res[i]=res[i]*right;
            right*=nums[i];

        }
        return res;
    }
};
