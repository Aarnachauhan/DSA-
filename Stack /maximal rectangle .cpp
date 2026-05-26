lc 85

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> currrow(m);

        //convert to integer
        for(int i=0;i<m;i++){
            currrow[i]=matrix[0][i]-'0';
        }

        int maxans=largestRectangleArea(currrow);
        for(int i=1;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]=='1'){ //got runtime here
                currrow[j]++;
            }
            else{
                currrow[j]=0;
            }

           }
           int currans=largestRectangleArea(currrow);
           maxans=max(maxans,currans);
        }
        return maxans;
    }
};
