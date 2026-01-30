// User function Template for C++
gfg

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m= grid[0].size();
          if (grid[source.first][source.second] == 0 ||
        grid[destination.first][destination.second] == 0) return -1;
        if(source.first==destination.first && source.second==destination.second) 
    return 0;
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int d=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=0;i<4;i++){
                int newr=row+ dr[i];
                int newc=col+ dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 &&
                d +1 <dist[newr][newc] ){
                    dist[newr][newc]=1+d;
                    
                    if(newr==destination.first && newc==destination.second) return d+1;
                    q.push({1+d,{newr,newc}});
                }
                
            }
          
        }
        return -1;
    }
};
