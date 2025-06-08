leetcode 678
tc-O(n)
sc-o(1)

class Solution {
public:
    bool checkValidString(string s) {
       int min=0;
       int max=0;
       int l=s.length();
       for(int i=0;i<l;i++){
        if(s[i]=='(') {
            max++;
        }
        else if(s[i]==')'){
            min--;
            max--;

        }
        else if(s[i]=='*'){
            min--;
            max++;
        }
        if(max<0) return false ; //more no of closing bracket than opening bracket.
        if(min<0) min=0;
       }
       return min==0;
        
    }
};
