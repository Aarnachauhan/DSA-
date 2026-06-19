lc 260
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll=0;
        for(auto x: nums){
            xorAll^=x;
        }
        long long rightmost=xorAll &(-xorAll);
        int a=0 , b=0;
        for(auto x:nums){
            if(x &rightmost){
                a^=x;
            }
            else b^=x;
        }
        if(a>b) swap(a,b);
        return {a,b};
    }
};
