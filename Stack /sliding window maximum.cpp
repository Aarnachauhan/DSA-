leetcode 239
tc-o(n-k)*(k)
sc-o(n-k)
brute force 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int > arr;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){  //O(n-k)
            maxi=nums[i];
            for(int j=i;j<i+k;j++){ //O(k)
                maxi=max(maxi,nums[j]);
            }
            arr.push_back(maxi);
        }
        return arr;
    }
};

optimal 
 // T.C = O(N) & S.C = O(N-K+1) + O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
