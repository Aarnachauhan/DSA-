lc 
tc-o(n + mlogm) //m is the no of unique elements , n is total no of elements
sc-O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }

        //step 2: transfer key value pairs to a vector
        vector<pair<int,int>> bucket;
        for(const auto & pair: freq){
            bucket.push_back(pair);
        }

        //step 3: sort the vector by freq in descending order
        sort(bucket.begin(),bucket.end(),[](const pair<int,int>& a , const pair<int,int> &b){
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(bucket[i].first);
        }
        return ans;
        
    }
};
