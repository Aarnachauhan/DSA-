//tc- o(3n) = o(n)
//sc-o(n) if we are considering modifying array as sc otherwise o(1)
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ind=-1;
      //here we are finding break point
        for(int i=n-2;i>=0;i--){ 0(n)
            if(arr[i]<arr[i+1]){
                ind=i;
                break;
            }
        }
      //if the permutation- [1,2,3,4,5] -> [5,4,3,2,1] and vice versa 
        if(ind==-1){
            reverse(arr.begin(),arr.end());
             return;
        }
      //finding smallest element that is greater than ind
        for(int i=n-1;i>ind;i--){ //o(n)
            if(arr[i]>arr[ind]){
                swap(arr[i],arr[ind]);
                break;
            }
        }
        reverse(arr.begin()+ind+1,arr.end()); o(n)
    }
};
