lc 40
Complexity
Time complexity:
O(2^n) where n is the no of candidates

Space complexity:
O(k*x) , where k is the average length of each combination
and x is the no of possible combination

additionally o(n) for recursive stack call

class Solution {
public:

void f(int ind,int target,vector<int>&candidates,vector<vector<int>> &ans,vector<int> &ds){

if(target==0){
    ans.push_back(ds);
    return;
}
for(int i=ind;i<candidates.size();i++){
    if(i>ind && candidates[i]==candidates[i-1]){
        continue;
    }
    if(candidates[i]>target) break;

    ds.push_back(candidates[i]);

   f(i+1,target-candidates[i],candidates,ans,ds);
   ds.pop_back();
}
}


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,target,candidates,ans,ds);
        return ans;
    }
};
