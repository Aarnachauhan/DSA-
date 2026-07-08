gfg
tc-O(n) +o(n)
sc-o(n)+O(n)
  result + stack
//this code handles ^ this case also
class Solution {
  public:
  
 int prec(char str){
     if(str=='^') return 3;
     else if(str=='*' || str=='/') return 2;
     else if(str=='+' || str=='-') return 1;
     else return -1;
 }
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string result;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
                result+=c;
            }
            else if(c=='('){
                st.push('(');
            }
            else if(c==')'){
                while(st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() &&
                    st.top() != '(' &&
                        (prec(st.top()) > prec(c) ||
                          (prec(st.top()) == prec(c) && c != '^')))
                                {
                                    result += st.top();
                                    st.pop();
            }
            st.push(c);
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};

