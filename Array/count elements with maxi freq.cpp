lc 3005
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int, int> mpp;
       int n=nums.size();
       for(int i=0;i<n;i++){
          mpp[nums[i]]++;
       }
       int maxi=0;
       for(const auto & entry : mpp){
        maxi=max(maxi , entry.second);
       }
       int cnt=0;
       for(const auto &entry : mpp){
        if(entry.second==maxi) cnt++;
       }
       int total=maxi*cnt;

       return total;
    }
};
