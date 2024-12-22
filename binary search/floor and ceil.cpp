class Solution {

  public:
  int findfloor(vector<int> arr,int x){
          int n=arr.size();
      int low=0; int high=n-1;
  
      int ans=-1;
      while(low<=high){
         int mid=(low+high)/2;
         if(arr[mid]<=x){
             ans=arr[mid];
             low=mid+1;
             
         }
         else{
             high=mid-1;
         }
 
      }   
      return ans;
  }
  
 int findceil(vector<int> &arr,int x){
     int low=0;
     int n=arr.size();
     int high=n-1;
     int ans=-1;
     while(low<=high){
      int mid=(low+high)/2;
      if(arr[mid]>=x){
          ans=arr[mid];
          high=mid-1;
      }
  
      else{
          low=mid+1;
      }
 
     } 
  return ans;
 }  
  
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        //if array is not sorted
        sort(arr.begin(),arr.end());
        int f=findfloor(arr,x);
        int c=findceil(arr,x);
        return {f,c}; // vector returns pair in this form 
    }
};
