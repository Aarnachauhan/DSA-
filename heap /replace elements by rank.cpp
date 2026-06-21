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
