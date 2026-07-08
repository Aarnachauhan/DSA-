gfg


class Solution {
  public:
    string postToPre(string s) {
        // code here
        stack<string> st;
        for(char c: s){
            if(isalnum(c)){
                st.push(string(1,c));
            }
            else{
                string op2=st.top();
                st.pop();
                
                string op1=st.top();
                st.pop();
                
                string temp=c + op1 + op2;
                st.push(temp);
            }
        }
        return st.top();
    }
};
