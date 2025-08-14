majority element ii - leetcode
  class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        //store the value and its freq in map
        for(int i=0;i<n;i++){
           mpp[nums[i]]++;
        }
        int more=n/3;
        vector<int> ans;
        for(auto pair : mpp){
            int element=pair.first;
            int count=pair.second;

            if(count>more){
                ans.push_back(element);
            }
        }
        return ans;
    }
};
