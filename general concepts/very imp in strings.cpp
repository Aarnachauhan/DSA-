lc 3941

for lower letter it is 97 to 122
  for upper letter it is 65 to 90


  
class Solution {
public:
    int passwordStrength(string p) {
        int n=p.size();
        unordered_set<char> st;
        for(auto i:p)
            {
                st.insert(i);
            }
        int ans=0;

        for(auto it:st)
            {
                char c=it;
                
                if(c>=97 && c<=122)
                    ans+=1;
                if(c>=65 && c<=90)
                    ans+=2;
                if(isdigit(c))
                    ans+=3;
                if(c=='!' || c=='@' || c=='#' || c=='$')
                    ans+=5;
            }
        return ans;
    }
};
