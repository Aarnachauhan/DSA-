gfg

brute force - 1110/1115 - tle
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int xor1=0;
            for(int j=i;j<n;j++){
                xor1=xor1^arr[j];
                if(xor1==k) cnt++;
            }
        }
        return cnt;
    }
};

optimal approach 
