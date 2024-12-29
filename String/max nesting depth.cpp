class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int result=0;
        for(char &c: s){
            if(c=='('){
                counter++;
            }else if(c==')'){
                counter--;
            }
            result=max(counter,result);
        }
        return result;
    }
};
