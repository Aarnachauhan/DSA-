gfg

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int repeat=-1;
        for(int i=0;i<n;i++){
            int val=abs(arr[i]);
            if(arr[val-1]>0){
                arr[val-1]=-arr[val-1];
            }
            else{
                repeat=val;
            }
        }
        
        int missing=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                missing=i+1;
                break;
            }
        }
        return {repeat,missing};
    }
};
