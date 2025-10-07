leetcode 500
tc-o(n*m)
sc-o(1)  as row[128] is fixed size
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int row[128]={0};
        string r2= "asdfghjklASDFGHJKL";
        string r3="zxcvbnmZXCVBNM";
        int n=r2.size();
        int m=r3.size();
        for(int i=0;i<n;i++){
            row[r2[i]]=1;
        }
        for(int i=0;i<m;i++){
            row[r3[i]]=2;
        }
        vector<string> res;
        for(int i=0;i<words.size();i++){
            int base=row[words[i][0]];
            bool ok=true;

            for(int j=1;j<words[i].size();j++){
                if(row[words[i][j]]!=base){
                    ok=false;
                    break;
                }
            }
            if(ok) res.push_back(words[i]);
        }
        return res;
    }
};
