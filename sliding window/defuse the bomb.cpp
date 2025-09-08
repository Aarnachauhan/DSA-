leetcode 1652
tc-o(n*k)
sc-o(n)

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> res(n,0);

        for(int i=0;i<n;i++){
            if(k>0){
                for(int j=i+1;j<i+1+k;j++){
                    res[i]+=code[j%n];
                }
            }
            else if(k<0){
                for(int j=i-1;j>i-1-abs(k);j--){
                    res[i]+=code[((j%n)+n)%n];
                }
            }
        }
        return res;
    }
};

sliding window 
tc-o(n)
sc-o(n) 

  
