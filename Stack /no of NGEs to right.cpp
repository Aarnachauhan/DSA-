gfg
we have a optimal approach also - binary tree

better approach:
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n=arr.size();
        vector<int> greater(n,0);
        multiset<int> seen;
        for(int i=n-1;i>=0;i--){
            auto it=seen.upper_bound(arr[i]);
            greater[i]=distance(it,seen.end());
            
            seen.insert(arr[i]);
        }
        vector<int> res;
        for(int id:indices){
            res.push_back(greater[id]);
        }
        return res;
    }
};
