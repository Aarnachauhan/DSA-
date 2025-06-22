leetcode 2138
tc-o(n)
sc-o(k) //for temp
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> result;

        int i=0;
        while(i<n){
            int j=(i+k-1 >=n)? (n-1) : (i+k-1);
            string temp=s.substr(i,j-i+1); //(i,k);

            if(j-i+1<k){
                int rem=k-(j-i+1);
                temp+=string(rem,fill);
            }
            result.push_back(temp);
            i+=k;

        }
        return result;
    }
};
