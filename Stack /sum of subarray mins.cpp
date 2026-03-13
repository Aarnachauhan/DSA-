see striver's video
leetcode 
  
  class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const int MOD= 1e9+7;
        long long res=0;

        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])){
            int mid=st.top();
            st.pop();

            int left=st.empty()? mid+1 : mid-st.top();
            int right=i-mid;

            res=(res+(long long)arr[mid]*left*right)%MOD;
        }
       st.push(i);
        }
        return res;
    }
};
