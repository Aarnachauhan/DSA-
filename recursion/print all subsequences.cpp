leetcode
//tc-o(2^n) same sc

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; //to store all the subsequences
        vector <int> subset; //to temporary store the current subsequence

        createsubset(nums,0,res,subset);
        return res;
    }
    void createsubset(vector<int> &nums,int index, vector<vector<int>> &res, vector<int> &subset){
        if(index==nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[index]); //take 
        createsubset(nums,index+1,res,subset);

        subset.pop_back(); //remove /dont take
        createsubset(nums,index+1,res,subset);
    }
};
