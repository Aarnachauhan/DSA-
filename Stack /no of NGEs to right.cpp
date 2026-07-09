gfg
we have a optimal approach also - binary tree
brute force
tc-o(n2)
sc-o(n)

class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n=arr.size();
        vector<int> ans;
       for(int i=0;i<indices.size();i++){
           int ind=indices[i];
           int cnt=0;
            for(int j=ind+1;j<n;j++){
                if(arr[j]>arr[ind]){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};



better approach:
tc-o(nlogn)
sc-O(n)
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
