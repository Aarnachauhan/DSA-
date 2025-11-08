leetcode 806 
tc-o(n)
sc-o(1)


class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum=0;
        int c=1;
        for(int i=0;i<s.length();i++){
            sum+=widths[s[i]-'a'];
            if(sum>100){
                c++;
                sum=widths[s[i]-'a']; //widths[97-97] = widths[0]
            }
        }
        return {c,sum};
    }
};
