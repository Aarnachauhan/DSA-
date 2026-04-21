lc 3684

class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end()); //remove duplicates
        vector<int> slist(s.begin(),s.end()); //convert to list
        sort(slist.rbegin(),slist.rend()); //descending order
        if(k> slist.size()) k=slist.size();
        return vector<int> (slist.begin(),slist.begin()+k); //return
    }
};
