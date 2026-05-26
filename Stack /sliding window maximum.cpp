leetcode 239

brute force 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int > arr;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            maxi=nums[i];
            for(int j=i;j<i+k;j++){
                maxi=max(maxi,nums[j]);
            }
            arr.push_back(maxi);
        }
        return arr;
    }
};

optimal 
