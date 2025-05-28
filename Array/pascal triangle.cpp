this question has 3 types . see notes . 
tc- o(n2)
sc-O(1)

class Solution {
public:
vector<int> generaterow(int row){
    long long ans=1;
    vector<int> rowans;
    rowans.push_back(1);
    for(int col=1;col<row;col++){
        ans= ans * (row-col);
        ans=ans/(col);
        rowans.push_back(ans);
     }
     return rowans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            res.push_back(generaterow(i));
        }
        return res;
    }
};
