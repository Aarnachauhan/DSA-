leetcode 560
tc - O(n) when we take best case of unordered_map 
worst case of unordered_map O(n * log n) 
if we take ordered map then O(n *n) 
sc- O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int presum=0;
        int cnt=0;
        mpp[0]=1;
        for(int num: nums){
            presum+=num;
            if(mpp.find(presum-k)!=mpp.end()){
                cnt+=mpp[presum-k];
            }
            mpp[presum]++;
        }
        return cnt;
    }
};
