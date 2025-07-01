leetcode 594
tc-o(nlogn) //logn for sorting 
sc-o(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      
        int j=0;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            while(nums[i]-nums[j]>1) j++;
            if(nums[i]-nums[j]==1){
                maxi=max(maxi,i-j+1);
            }
        }
       return maxi;
    }
};
