leetcode 3304
tc-o(1 + 2+ 4....+k)
sc-o(k)
learn z to a mapping from this problem 

class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            int size=s.length();
            for(int i=0;i<size;i++){
                char nextchar='a' + ((s[i]-'a' + 1)%26);
                s+=nextchar;
            }
        }
        return s[k-1];
    }
};
