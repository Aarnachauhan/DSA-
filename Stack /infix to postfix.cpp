gfg
tc-O(n) +o(n)
sc-o(n)+O(n)
  result + stack

public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c){
        if(c=='^') return 3;
        else if(c=='/' || c=='*') return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    }
    

    string infixToPostfix(string& s) {
        // Your code here
        stack<char> st;
        string result;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if((c>='a' && c<='z') ||(c>='A' && c<='Z') ||(c>='0' && c<='9') ){
                result+=c;
            }
            else if(c=='('){
                st.push('(');
            }
            else if(c==')'){
                while(st.top()!='('){ //o(n)
                    result+=st.top();
                    st.pop();
                }
                st.pop(); // ( isko bhi pop krdo
            }
            else{
                while(!st.empty() && prec(s[i])<=prec(st.top())){ //o(n)
                    result+=st.top();
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
  
