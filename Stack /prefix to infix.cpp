tc-o(2n)
  sc-o(n)
gfg
class Solution {
  public:
 bool isoperator(char x){
     switch(x){
         case '+':
         case '-':
         case '/':
         case '*':
         case '^':
         case '%':
         return true;
     }
     return false;
 }
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> s;
        int len=pre_exp.size();
        
        for(int i=len-1;i>=0;i--){
            if(isoperator(pre_exp[i])){
                string op1=s.top();
                s.pop();
                string op2=s.top();
                s.pop();
                string temp="("+ op1+ pre_exp[i] +op2+")";
                s.push(temp);
                
            }
            else{
                s.push(string(1,pre_exp[i]));
                
            }
        }
        return s.top();
    }
