leetcode 16
tc-o(n2) 
sc-o(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closetsum=INT_MAX/2;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
           int j=i+1, k=n-1;
           while(j<k){
            int currentsum=nums[i]+nums[j]+nums[k];
            if(abs(currentsum-target)<abs(closetsum-target)){
                closetsum=currentsum;
            }
            if(currentsum<target) j++;
            else if(currentsum>target) k--;
            else return currentsum; //equals to target
           }
        }
        return closetsum;
    }
};
