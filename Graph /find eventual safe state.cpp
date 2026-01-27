leetcode 802
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodes=graph.size();
        vector<vector<int>> rev(nodes);
       vector<int> indegree(nodes, 0);
        //reverse the edge and store indegrees of all the nodes
        for(int i=0;i<nodes;i++){
            for(auto it:graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safenode;
         //if indegree==0 then put it in queue
        for(int i=0;i<nodes;i++){
            if(indegree[i]==0) q.push(i);
        }

        //kahn's algo
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenode.push_back(node);

            for(auto it: rev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
       sort(safenode.begin(),safenode.end());
       return safenode;
    }
};
