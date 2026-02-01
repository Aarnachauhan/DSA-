gfg
tc-o(n^3)
// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        for(int val=0;val<dist.size();val++){
            for(int i=0;i<dist.size();i++){
                for(int j=0;j<dist[i].size();j++){
                    if(dist[i][val]==1e8 || dist[val][j]==1e8) continue;
                    
                    dist[i][j]=min(dist[i][val]+dist[val][j],dist[i][j]);
                }
            }
            
        }
        
    }
};
