lc 1021 
// when 0>0 and its false , still then open+=1 will work
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int open=0;
        for(char c: s){
            if(c=='(' && open++>0){
              
                res+=c;
            }
            if(c==')' && open-->1){
                res+=c;
            }
        }
        return res;
    }
};
