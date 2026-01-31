gfg
tc-o(10^5 * arr.size)
// User function Template for C++
#define MOD 100000
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        queue<pair<int,int>> q;
        vector<int> vis(MOD,1e9);
        
        q.push({start,0}); //steps, node
        vis[start]=0;
        
        
        while(!q.empty()){
            int node=q.front().first;
            int op=q.front().second;
            q.pop();
            
            for(auto it:arr){
                int num=(it*node)%MOD;
                if(op+1<vis[num]){
                    vis[num]=op+1;
                    
                    if(num==end) return op+1;
                    q.push({num,op+1});
                }
            }
        }
        return -1;
        
    }
};
