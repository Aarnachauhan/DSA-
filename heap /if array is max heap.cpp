gfg
tc-o(n)
sc-o(1)

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n=arr.size();
        for(int i=0;i<n/2;i++){
            int left=2*i+1;
            int right=2*i+2;
            
            if(arr[left]>arr[i]) return false;
            if(right<n && arr[right]>arr[i]) return false;
            
        }
        return true;
    }
};
