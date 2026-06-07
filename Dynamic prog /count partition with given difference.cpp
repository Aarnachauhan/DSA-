gfg : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

recursive code:
TC O(2^N)
SC O(N)
class Solution {
  public:
  
 int f(int ind , vector<int> &arr, int target){
     if(ind==0){
     if(target==0 && arr[0]==0) return 2;
     if(target==0 || target==arr[0]) return 1;
     return 0;
     }
     
     int notpick=f(ind-1 , arr, target);
     int pick=0;
     if(arr[ind]<=target){
         pick=f(ind-1,arr,target-arr[ind]);
     }
     return pick+ notpick;
 }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalsum=accumulate(arr.begin(),arr.end(),0);
        if(totalsum-diff <0 ||(totalsum-diff)%2!=0 ) return 0;
        
        int target=(totalsum-diff)/2;
        return f(n-1,arr,target);
    }
};
-------------------------------------------------------------------------
memoization 
  
