gfg


class Solution {
  public:
    string preToPost(string &s) {
        // code here
        stack<string> st;
        for(int i=s.length()-1;i>=0;i--){
            char c=s[i];
           if(isalnum(c)){
               st.push(string(1,c));
           }
           else{
               string op1=st.top();
               st.pop();
               
               string op2=st.top();
               st.pop();
               
               string temp=op1 + op2 + c;
               st.push(temp);
           }
           
        }
        return st.top();
    }
};
