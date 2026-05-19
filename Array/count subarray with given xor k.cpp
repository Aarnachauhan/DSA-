gfg
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> freq;
        freq[0]=1;
        int prefix=0;
        int cnt=0;
        for(int num:arr){
            prefix^=num;
            int target=prefix^k;
            if(freq.find(target)!=freq.end()){
                cnt+=freq[target];
            }
            
            freq[prefix]++;
        }
        return cnt;
    }
};
