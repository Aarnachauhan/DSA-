gfg

naive-
tc-o(n*m + n*m log(n*m))
sc-o(1) // not counting list which we using for storing.
  class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> list;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                list.push_back(mat[i][j]);
            }
        }
        sort(list.begin(),list.end());
        return list[(n*m)/2];
    }
};

optimal 
