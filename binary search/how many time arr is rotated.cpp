//approach- find how minimum element in rotated sorted array and store its index

gfg
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int s=0;
        int n=arr.size();
        int e=n-1;
        int ind=-1;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[s]<=arr[e]){ //search space is sorted
                if(arr[s]<ans){
                    ind=s;
                    ans=arr[s];
                     }
                     break;
            }
            
            if(arr[s]<=arr[mid]){ //lefy part is sorted
                if(arr[s]<ans){
                    ind=s;
                    ans=arr[s];
                }
                s=mid+1; //eliminate left part
            }
            else{ //right part is sorted
                if(arr[mid]<ans){
                    ind=mid;
                    ans=arr[mid];
                }
                e=mid-1;
            }
        }
        return ind;
    }
};
