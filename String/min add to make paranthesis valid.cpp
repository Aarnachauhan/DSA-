leetcode 921
tc-o(n)
sc-o(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.length();
        int open=0, add=0;
        for(char c:s){
            if(c=='('){
                open++;
            }
            else if(c==')'){
                if(open>0){
                    open--;
                }
                else add++;
            }
        }
        return open+add;
       
    }
};
