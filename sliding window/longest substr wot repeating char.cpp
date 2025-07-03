leetcode 3
using set
tc-o(n)
sc-o(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxi=0;
        int l=0;
        unordered_set<char> charset;
        for(int r=0;r<n;r++){
            while(charset.find(s[r])!=charset.end()){
                charset.erase(s[l]);
                l++;
            }
            charset.insert(s[r]);
            maxi=max(maxi, r-l+1);
        }
        return maxi;
    }
};

using sliding window
