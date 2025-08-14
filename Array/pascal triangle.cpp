this question has 3 types . see notes . 
tc- o(n2)
sc-O(1)
explanation from leetcode submissions 
➤ i = 0

 row = [1]
 Push to pascal → [[1]]

➤ i = 1

 row = [1, 1]
 No inner loop needed (length = 2)
 Push to pascal → [[1], [1, 1]]

➤ i = 2

 row = [1, _, 1]
 Inner loop: j = 1
   row[1] = pascal[1][0] + pascal[1][1] = 1 + 1 = 2
   Now: row = [1, 2, 1]
 Push → [[1], [1, 1], [1, 2, 1]]

➤ i = 3

 row = [1, _, _, 1]
 Inner loop:
   j = 1: row[1] = pascal[2][0] + pascal[2][1] = 1 + 2 = 3
   j = 2: row[2] = pascal[2][1] + pascal[2][2] = 2 + 1 = 3
   Now: row = [1, 3, 3, 1]
 Push → [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

➤ i = 4
 row = [1, _, _, _, 1]
 Inner loop:
    j = 1: row[1] = pascal[3][0] + pascal[3][1] = 1 + 3 = 4
    j = 2: row[2] = pascal[3][1] + pascal[3][2] = 3 + 3 = 6
    j = 3: row[3] = pascal[3][2] + pascal[3][3] = 3 + 1 = 4
    Now: row = [1, 4, 6, 4, 1]
 Push → [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]


code -
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i = 0; i<numRows; i++){
            vector<int> row(i+1, 1);
            for(int j = 1; j< i; j++){
                row[j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};

code 2- striver
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
