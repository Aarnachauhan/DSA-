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
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> res(N, 0);
        if (k == 0) return res;

        int step = abs(k);
        int sum = 0;

        // starting window: sum next k elements if k > 0
        // or previous k elements if k < 0
        if (k > 0) {
            for (int i = 1; i <= k; i++) {
                sum += code[i % N];
            }
            res[0] = sum;

            for (int i = 1; i < N; i++) {
                // remove outgoing, add incoming
                sum -= code[i % N];
                sum += code[(i + k) % N];
                res[i] = sum;
            }
        } else {
            for (int i = 1; i <= step; i++) {
                sum += code[(N - i) % N];
            }
            res[0] = sum;

            for (int i = 1; i < N; i++) {
                // remove outgoing, add incoming
                sum -= code[(i - 1 - step + N) % N];
                sum += code[(i - 1 + N) % N];
                res[i] = sum;
            }
        }

        return res;
    }
};

  
