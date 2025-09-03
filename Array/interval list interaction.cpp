leetcode 986
tc-O(n+ m)
sc-o(n) // for storing answer
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n=firstList.size() ;
         int m= secondList.size();

         int i=0, j=0;
         while(i<n && j < m ){
            int start= max(firstList[i][0] , secondList[j][0]);
            int end= min(firstList[i][1], secondList[j][1]);

            if(start<=end) res.push_back({start, end});
            if(firstList[i][1]<secondList[j][1]) i++;
            else j++;
         }
        return res;
    }
};
