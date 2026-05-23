lc 503
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        vector<int> res(n,-1);
        vector<int> st;

        for(int i=2*n-1; i>=0 ; --i){
            int curr=nums[i%n];
            while(!st.empty() && st.back()<=curr) st.pop_back();
            if(i<n) res[i]=st.empty()?-1 : st.back();
            st.push_back(curr);
        }
        return res;
    }
};
