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
