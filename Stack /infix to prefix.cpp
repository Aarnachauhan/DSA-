gfg

class Solution{
public:

int prec(char c){

    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;

    return -1;
}

string infixToPrefix(string s){

    reverse(s.begin(),s.end());

    for(char &c:s){

        if(c=='(')
            c=')';

        else if(c==')')
            c='(';
    }

    stack<char> st;

    string ans;

    for(char c:s){

        if(isalnum(c))
            ans+=c;

        else if(c=='(')
            st.push(c);

        else if(c==')'){

            while(st.top()!='('){

                ans+=st.top();
                st.pop();
            }

            st.pop();
        }

        else{

            while(!st.empty() &&
                  st.top()!='(' &&
                  prec(st.top())>prec(c)){

                ans+=st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while(!st.empty()){

        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}
};
