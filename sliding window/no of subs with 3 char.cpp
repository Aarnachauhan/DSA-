leetcode 1358
tc-o(N)
sc-o(1) as only 1 fixed array is used.

 class Solution {
public:
    int numberOfSubstrings(string s) {
        int abc[3]={-1,-1,-1};
        int cnt=0;
        int point=0;
        while(point<s.length()){
            abc[s[point]-'a']=point; //for this line see notes
            int minind=INT_MAX;
            for(int i=0;i<3;i++){
               minind=min(minind,abc[i]);
            }
            cnt+=(minind+1);
            point++;
        }
        return cnt;
    }
};
