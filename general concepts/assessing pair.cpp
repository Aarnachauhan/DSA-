leetcode 409
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        int cnt=0;
        bool odd=false;

        for(char ch:s){
            freq[ch]++;
        }

        for(auto & pair : freq){
            if(pair.second %2==0){
                cnt+=pair.second;
            }
            else {
                cnt+=pair.second-1;
                odd=true;
            }
        }
        if(odd){
            return cnt+1;
        }
        return cnt;

    }
};
