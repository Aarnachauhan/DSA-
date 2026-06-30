lc 3975
tc-O(nlogn)
sc-o(n)

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        vector<vector<int>> merged;
        //merge overlapping intervals
        for(auto &it: occupiedIntervals){
            if(merged.empty() || it[0] > (long long) merged.back()[1] +1){ //no overlap
                merged.push_back(it);
            }else{
              merged.back()[1]= max(it[1] , merged.back()[1]);
            }
        }

        vector<vector<int>> ans;

        //remove free intervals:

        for(auto &it: merged){
           int l=it[0];
           int r=it[1];

            if(r <freeStart || l > freeEnd){ //no overlap
                ans.push_back({l,r});
                continue;
            }
            //left overlap
            if(l<freeStart){
                ans.push_back({l,freeStart-1});
            }
            //right overlap
            if(r>freeEnd){
               ans.push_back({freeEnd+1,r});
            }

        }


        return ans;
    }
};
