leetcode 219
better solution
tc-o(n)
sc-o(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                if(i-mpp[nums[i]]<=k) return true;
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};

brute force - time limit exceeded
tc--o(n2)
sc--o(1)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int n=nums.size();
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             if(nums[j]==nums[i]){
                if(j-i <=k) return true;
             }
        }
       }
       return false;
    }
};

optimal 
tc-o(n)
sc-o(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int,int> mpp;
       int n=nums.size();
       for(int i=0;i<n;i++){
          if(mpp.count(nums[i])) return true;
          mpp[nums[i]]=i;

          if(mpp.size()>k) {
            mpp.erase(nums[i-k]);
          }
       }
       return false;
    }
};
