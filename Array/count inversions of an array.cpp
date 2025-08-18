gfg

brute force- code written by me ! hehhehe
  tle  1110/1115
  class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j] && i<j){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


optimal
