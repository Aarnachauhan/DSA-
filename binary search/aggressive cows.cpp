gfg
brute force
tc-o(max-min) * o(n)
sc=o(1)

class Solution {
  public:
  bool canplace(vector<int> &stalls ,int dist, int cows){
      int n=stalls.size();
      int cntcows=1;
      int last=stalls[0];
      for(int i=1;i<n;i++){
          if(stalls[i]-last >=dist){
              cntcows++;
              last=stalls[i];
          }
          if(cntcows>=cows) return true;
      }
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int limit=stalls[n-1]-stalls[0];
        for(int i=1;i<=limit;i++){
            if(canplace(stalls,i,k)==false) return (i-1);
        }
        return limit;
    }
};
