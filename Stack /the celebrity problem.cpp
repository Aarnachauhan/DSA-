gfg


brute force
tc-o(n2) sc- o(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int > indegree(n,0) , outdegree(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=mat[i][j];
                indegree[j]+=x;
            outdegree[i]+=x;
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==n && outdegree[i]==1) return i;
        }
        
        return -1;
    }
};

better solution 
tc-o(n) sc-O(n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        stack<int> st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            if(mat[a][b]) st.push(b);
            else st.push(a);
        }
        int c=st.top();
        for(int i=0;i<n;i++){
            if(i==c) continue;
            //if celeb knows someone =false
            //if someone doesnt know celeb=false
            if(mat[c][i] || !mat[i][c]){ 
                return -1;
            }
        }
        return c;
    }
};
