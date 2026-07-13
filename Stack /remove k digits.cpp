class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c: num){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k>0){ //this is for ex:4567
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

         reverse(ans.begin(),ans.end());
         int i=0;
        while(i<ans.size() && ans[i]=='0'){ //for trailing zeros
            i++;
        }

        ans=ans.substr(i);

        if(ans=="") return "0";

        return ans;
    }
};
