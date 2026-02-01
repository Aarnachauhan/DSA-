leetcode 1976

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

         priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(dis> dist[node]) continue;

            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                //this is the first time i am coming with this short distance 
                if(dis+wt<dist[adjnode]){
                  dist[adjnode]=dis+wt;
                  pq.push({dis+wt,adjnode});
                  ways[adjnode]=ways[node];
                }

                else if(dis + wt ==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%MOD;
                }

            }

        }
       return ways[n-1];
    }
};
