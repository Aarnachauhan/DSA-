
gfg
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> ans;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
