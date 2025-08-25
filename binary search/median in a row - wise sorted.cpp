gfg

naive-
tc-o(n*m + n*m log(n*m))
sc-o(n*m) 
  class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> list;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                list.push_back(mat[i][j]);
            }
        }
        sort(list.begin(),list.end());
        return list[(n*m)/2];
    }
};

optimal 
class Solution {
  public:
int upperbound(vector<int> &matrix , int x , int n){
    int low=0 ; int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(matrix[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int countsmallelements(vector<vector<int>> &mat , int n , int m , int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upperbound(mat[i],x,m);
    }
    return cnt;
}
    int median(vector<vector<int>> &mat) {
        // code here
        int low=INT_MAX ;
        int high=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            low=min(low , mat[i][0]);
            high=max(high, mat[i][m-1]);
        }
        int req=(n*m)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smallequals=countsmallelements(mat,n,m,mid);
            if(smallequals <=req) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
