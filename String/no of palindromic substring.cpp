leetcode 647
we can do this by dp also
tc-o(N2)
sc-O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
           cnt+=expand(s,i,i);
           cnt+=expand(s,i,i+1);
        }
        return cnt;
    }

    int expand(string &s , int left , int right){
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;

        }
        return count;
    }
};
