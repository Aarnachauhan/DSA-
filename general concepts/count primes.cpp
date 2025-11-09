leetcode 204
tc-o(nloglogn)
sc-o(n)

class Solution {
public:
    int countPrimes(int n) {
       if(n<=2) return 0;
       vector<bool> prime(n+1,true);
       prime[0]=0;
       prime[1]=0;
       prime[2]=1;
       int cnt=1;
       for(int i=3;i<n;i=i+2){
        if(prime[i]){
            cnt++;
            for(int j=i*2;j<n;j+=i){
                prime[j]=0;
            }
        }
       }
       return cnt;
    }
};
