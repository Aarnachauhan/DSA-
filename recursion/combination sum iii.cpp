lc 210


class Solution {
public:
void f(int num , int k , int target, vector<int> &temp , vector<vector<int>> &ans){
    if(target==0 && temp.size()==k){
       ans.push_back(temp);
       return;
    }
    if(num>9) return;
    if(num<1) return;
    temp.push_back(num);
    f(num+1,k,target-num,temp,ans);
    temp.pop_back();
    f(num+1,k,target,temp,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1,k,n,temp,ans);
        return ans;
    }
};

better:
class Solution {
public:

    void f(int start,
           int k,
           int target,
           vector<int>& temp,
           vector<vector<int>>& ans){

        if(target == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }

        if(target < 0)
            return;

        if(temp.size() > k)
            return;

        for(int i = start; i <= 9; i++){

            temp.push_back(i);

            f(i+1,
              k,
              target-i,
              temp,
              ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> temp;

        f(1,k,n,temp,ans);

        return ans;
    }
};
