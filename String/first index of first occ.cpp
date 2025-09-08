leetcode 28
tc-o(n*m)
sc-o(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
       
    int n=haystack.length();
    int m=needle.length();
    int ind=0;
    for(int i=0;i<n;i++){
        if(haystack[i]==needle[ind]) ind++;
        else {
            i=i-ind;
            ind=0;
        }
        if(ind==m) return i-m+1;   // <-- difference here
    }
    return -1;
    }

};
