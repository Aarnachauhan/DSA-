class Solution {
public:
  int firstocc(vector<int> &arr,int n,int target){
int low=0;
int high=n-1;
int first=-1;
while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==target){
        first=mid;
        high=mid-1; //first occurence k liye left mai jana padega
    }else if(arr[mid]<target){
        low=mid+1; //right mai hi milega
    }
    else{
        high=mid-1; //left mai milega
    }
}
    return first;
}

int lastocc(vector<int> &arr,int n,int target){
int low=0;
int high=n-1;
int last=-1;
while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==target){
        last=mid;
        low=mid+1;
    }
    else if(arr[mid]<target){
     low=mid+1;
    }
    else{
        high=mid-1;
    }
}
    return last;
}
pair<int,int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int first=firstocc(arr,n,target);
        if(first==-1) return {-1,-1};
        int last=lastocc(arr,n,target);
        return {first,last};
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        pair<int,int> ans=searchRange(arr, target);
        if(ans.first==-1) return 0;
        return ans.second - ans.first +1;
        
        
    }
};
