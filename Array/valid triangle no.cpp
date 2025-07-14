tc-o(n2)
sc-o(1)
leetcode 611
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        for(int k=2;k<n;k++){
          int num=nums[k] , i=0 ,j=k-1;
          while(i<j){
            if(nums[i] + nums[j] > num){
                count+= j-i;
                j--;
            }
            else i++;
          }
        }
        return count;
    }
};
