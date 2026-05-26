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

optimal : code written by me ( yayyy)))))))))) big winnn
class Solution {
public:
vector <int > prevsmaller(vector<int> &heights){
   vector<int > prev(heights.size());
   stack<int> st;
   for(int i=0;i<heights.size();i++){
     while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                prev[i] = -1;
            }
            else {
                prev[i] = st.top();
            }

            st.push(i);
   }
   return prev;
}

vector<int> nextsmaller(vector<int> &heights){
   vector<int > next(heights.size());
   stack<int> st;
   for(int i=heights.size()-1;i>=0;i--){
    while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                next[i] = heights.size();
            }
            else {
                next[i] = st.top();
            }

            st.push(i);
   }
   return next;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev= prevsmaller(heights);
        vector<int> next= nextsmaller(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int right=next[i];
            int left=prev[i];
            int total=(right-left-1);
            int area=heights[i]*total;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
