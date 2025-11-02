leetcode 547
tc-o(n2)
sc-o(n)+ o(n)
//visited array + recursion stack space

class Solution {
public:
void dfs(int node , vector<bool> &vis, vector<vector<int>> &isConnected){
    vis[node]=true; //mark current node as visited
    int n=isConnected.size(); //total no of cities
    for(int i=0;i<n;i++){
        if(isConnected[node][i]==1 && !vis[i]){ //if i is connected to node and not visited.
            dfs(i,vis,isConnected);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n, false); // all will  have false stored in it.
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};
