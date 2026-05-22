gfg
https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1


class Solution {
  public:
bool subsets(vector<int> & arr , int k , int ind ,int sum ){
    
    if(sum>k) return false; //stopping early
    if(sum==k) return true; //stopping early
    if(ind==arr.size()){
        return (sum==k);
        
    }
    
    sum+=arr[ind];
    if(subsets(arr, k , ind+1,sum )) return true;
    
    sum-=arr[ind];
    if(subsets(arr,k , ind+1,sum)) return true;
    
    return false;
}
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        //int sum=0;
        return subsets(arr,k,0, 0);
    }
};
