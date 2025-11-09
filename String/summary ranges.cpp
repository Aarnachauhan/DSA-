
leetcode 228


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()){
            return res;
        }
        for(int i=0;i<nums.size();){
            int start=nums[i];
            int j=i;

            while(j+1<nums.size() && nums[j+1]==nums[j]+1){
                j++;
            }

            if(nums[j]==start){
                res.push_back(to_string(start));
            }
            else{
                res.push_back(to_string(start)+"->" + to_string(nums[j]));
            }

            i=j+1;
        }
        return res;
    }
};
