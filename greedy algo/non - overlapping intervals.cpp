leetcode
tc- O(n logn + n ) // nlogn for sorting , n for iterating .
sc-o(1)


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res=0;

        sort(intervals.begin(),intervals.end(),[](const auto &a, const auto & b){
            return a[1] < b[1];
        }); 
        int prev_end = intervals[0][1];

        for(int i=1;i< intervals.size();i++){
            if( prev_end > intervals[i][0]){
                res++;
            } else {
                prev_end= intervals[i][1];
            }
        }
        return res;
    }
};
