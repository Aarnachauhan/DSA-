lc 84
brute force
tc-o(n2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=-1;
        int n=heights.size();
        for(int i=0;i<heights.size();i++){
            int left=i-1;
            int right=i+1;
            while(left>=0 && heights[i]<=heights[left]) left--;
            while(right<n && heights[i]<=heights[right]) right++;

            int area=(right-left-1)*heights[i];
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};

optimal
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area=0, n=heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
              int bar=st.top(); st.pop();
              int pse=st.empty() ? -1 : st.top();
              int nse=i;
              area=max(area, heights[bar]* (nse-pse-1));

            }
            st.push(i);
        }
        while(!st.empty()){
            int bar=st.top(); st.pop();
            int pse=st.empty()? -1:st.top();
            int nse=n;
            area=max(area, heights[bar]*(nse-pse-1));
        }
        return area;
    }
};
