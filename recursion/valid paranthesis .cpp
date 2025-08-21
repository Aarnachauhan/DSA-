leetcode 125
tc-o(n)
sc-o(n)

class Solution {
public:
    bool isPalindrome(string s) {
        return recur(s,0,s.size()-1);
    }

private:
    bool recur(string &s , int left , int right ){
        while(left < right &&!isalnum(s[left])) left++;
        while(left<right && !isalnum(s[right])) right--;

        if(left>=right) return true;

        if(tolower(s[left])!=tolower(s[right])) return false;

        return recur(s,left+1, right-1);
    }
};
