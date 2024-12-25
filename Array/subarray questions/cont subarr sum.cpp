leetcode 523

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int runningsum=0;
        int prefixsum=0;
        for(int i=0;i<nums.size();i++){
            runningsum+=nums[i];
            if(k!=0) prefixsum=runningsum%k;
            if(mp.find(prefixsum)!=mp.end()){
            if(i-mp[prefixsum]>1) return true; //i- phele wale sum ki index

            }else{
                mp[prefixsum]=i;
            }
        }
        
        return false;
    }
};
