perfect sum problem 
gfg
this needs optimization using dp
public:
    int prints(int ind,int s,vector<int> &arr,int target,int n){
        
        if(s>target) return 0; //use this line only if all no are positive
        if(ind==n){
            if(s==target){
            return 1;
        }else{
            return 0;
        }
        }
        s+=arr[ind];
        int l=prints(ind+1,s,arr,target,n);
        
        s-=arr[ind];
        int r=prints(ind +1 ,s,arr,target,n);
        
        return l+r;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int ind;
        int s;
        int n=arr.size();
        
        return prints(0,0,arr,target,n);
        
    }
