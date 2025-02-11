tc-o(n) + o(n) 
sc-o(n)
gfg
class Solution {
  public:
  bool isoperand(char x){
      return (x>='a' && x<='z') || (x>='A' && x<='Z');
  }
    string postToInfix(string exp) {
        // Write your code here
        stack<string> s;
        for(int i=0;exp[i]!='\0';i++){
            if(isoperand(exp[i])){
                string op(1,exp[i]);
                s.push(op);
            }
            else{
                string t1=s.top();
                s.pop();
                string t2=s.top();
                s.pop();
                s.push("(" + t2+ exp[i]+t1+")");
            }
        }
        return s.top();
    }
