lc 721
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mailToNode;

        // Step 1: Union accounts having same email
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                }
                else {
                    ds.unionByRank(i, mailToNode[mail]);
                }
            }
        }

        // Step 2: Collect emails for each parent
        vector<string> mergedMail[n];

        for (auto it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.findParent(node);

            mergedMail[parent].push_back(mail);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
