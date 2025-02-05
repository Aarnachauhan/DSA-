gfg
tc-o(n) + o(nlogn) 
  sc=o(1)

  class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long n=bt.size();
        sort(bt.begin(),bt.end());
        long long t=0;
        long long wait_time=0;
        
        for(int i=0;i<n;i++){
            wait_time+=t;
            t+=bt[i];
        }
        return wait_time/n;
    }
