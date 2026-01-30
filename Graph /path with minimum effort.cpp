leetcode 1631
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, 
               vector<pair<int,pair<int,int>>>, 
               greater<pair<int,pair<int,int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});  // {effort, {row, col}}
        
        // Step 2: Define 4 directions
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        // Step 3: Dijkstra's algorithm
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // Step 4: Check if we reached destination
            if(row == n-1 && col == m-1) return diff;
            
            // Step 5: Explore all 4 neighbors
            for(int i = 0; i < 4; i++) {
                int newr = row + delrow[i];
                int newc = col + delcol[i];
                
                if(newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    // Step 6: Calculate effort to reach neighbor
                    // Max of (current path's max effort, height difference to neighbor)
                    int newEffort = max(abs(heights[newr][newc] - heights[row][col]), diff);
                    
                    // Step 7: Update if we found a better path
                    if(newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        
        // Step 9: Default return (shouldn't reach here with valid input)
        return 0;
    }
};
