lc 1331


tc-o(nlogn)
sc-o(n)
using map:
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> rank;
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        int r=1;
        for(int x:temp){
            if(rank.find(x)==rank.end()){
                rank[x]=r;
                r++;
            }
        }

        vector<int> ans;
        for(int x:arr){
          ans.push_back(rank[x]);
        }
        return ans;
    }
};

using heap ( not a good solution)
tc-o(nlogn)
sc-o(n)
vector<int> replaceWithRank(vector<int>& arr, int n)
{
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    for(int x : arr)
        pq.push(x);

    unordered_map<int,int> rank;

    int r = 1;

    while(!pq.empty())
    {
        int x = pq.top();
        pq.pop();

        if(rank.find(x) == rank.end())
        {
            rank[x] = r;
            r++;
        }
    }

    vector<int> ans;

    for(int x : arr)
        ans.push_back(rank[x]);

    return ans;
}
