leetcode 2099
tc-o(n)
sc-o(N)

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            return nums;
        }
        vector<int> temp(nums); //temp==nums

        nth_element(begin(temp),begin(temp)+k-1, end(temp),greater<int>());
        //avg tc of this is O(n)
        int kth=temp[k-1];
        int countk=count(begin(temp),begin(temp)+k,kth);
        vector<int> res;
        for(auto &it:nums){
            if(it>kth){
                res.push_back(it);
            }else if(it==kth && countk>0){
                    res.push_back(it);
                    countk--;
            }

            if(res.size()==k) break;

        }

        return res;
    }
};
