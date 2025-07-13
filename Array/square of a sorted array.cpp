tc-o(n)
sc-o(n) , if we dont count res then o(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int l=0;
        int r=n-1;
        for(int i=n-1;i>=0;i--){
            if(abs(nums[l])> abs(nums[r])){
                res[i]=nums[l]*nums[l];
                l++;
            }
            else{
                res[i]=nums[r]*nums[r];
                r--;
            }
        }
        return res;
    }
};
