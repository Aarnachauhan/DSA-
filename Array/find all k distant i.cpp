leetcode 2200 . 
potd: 26-6-25

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        int r=0;
        vector<int> result;
       for(int j=0;j<n;j++){
        if(nums[j]==key){
            int start=max(r,j-k);
            r=min(n-1,j+k)+1;

            for(int i=start;i<r;i++){
                result.push_back(i);
            }

        }
       }
        return result;
    }
};
