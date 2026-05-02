lc 2032

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> cnt(101,0);
        auto process=[&](vector<int> & nums){
            unordered_set<int> seen(nums.begin(),nums.end());
            for(int x:seen){
                cnt[x]++;
            }
        };
        process(nums1);
        process(nums2);
        process(nums3);

        vector<int> res;
        for(int i=1;i<=100;i++){
          if(cnt[i]>=2){
            res.push_back(i);
          }
        }
        return res;
    }
};
