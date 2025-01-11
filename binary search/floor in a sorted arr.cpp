gfg
public:

    int findFloor(vector<int>& arr, int k) {

        // Your code here
        int low=0;
        int n=arr.size();
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe it is the answer
            if(arr[mid]<=k){
                ans=mid;
           
               low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
        
    }
