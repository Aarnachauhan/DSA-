tc-o(2n)
  sc-o(n)
gfg
       
class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        for(int i=pre_exp.size()-1 ;i>=0;i--){
            char c=pre_exp[i];
            
            if(isalnum(c)){
                st.push(string(1,c));
                
            }
            else{
                string op1=st.top();
                st.pop();
                
                string op2=st.top();
                st.pop();
                
                string temp='(' + op1 + c + op2 + ')';
                st.push(temp);
            }
            
        }
        return st.top();
    }
};
