gfg
// User function Template for C++
class Solution {
  private:
  tc- O(V+E)
  void topo(stack<int> &st, vector<pair<int,int>> adj[], int vis[], int node){
      vis[node]=1;
      for(auto &it :adj[node]){ //& is used because we are not copying it , bus refernce le rhe hai
          int v= it.first;
         
          
          if(!vis[v]){
              topo(st,adj,vis,v);
          }
      }
      st.push(node);
  }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        //make a adj list
        vector<pair<int,int>> adj[V]; //this is array of V vectors
        //fill the adj list with edges
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            
        }
        
        int vis[V]={0};
        //stack will give us total no of nodes = V  and for loop will run for total no of edges ( the for loop in while loop)
       //so it will be O(V+E)
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo(st,adj,vis,i);
            }
        }
        
        vector<int> dis(V);
        for(int i=0;i<V;i++){
            dis[i]=1e9;
            
        }
        //distance to the source node is 0 .
        dis[0]=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            
        //relax the all outgoing node to current node
        for(auto &it:adj[node]){
            int v=it.first;
            int wt=it.second;
            
             if (dis[node] + wt < dis[v]) {
            dis[v] = wt + dis[node];
          }
        }
        
        }
        
         for (int i = 0; i < V; i++) {
        if (dis[i] == 1e9) {
          dis[i] = -1;
        }
      }
      return dis;
        
        }
};
