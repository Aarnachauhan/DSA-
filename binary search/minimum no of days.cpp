tc-o(n*(log(maxi-mini+1))
sc 0(1)

  class Solution {
public: 

bool possible(vector<int>&bloomDay,int day,int m,int k){
int n=bloomDay.size();
int cnt=0;
int b=0;
for(int i=0;i<n;i++){
if(bloomDay[i]<=day){
    cnt++;
}
else{
    b+=(cnt/k);
    cnt=0;
}
}
b+=(cnt/k);
return b>=m;

}


    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL * k*1LL;
        if(val>bloomDay.size()) return -1;

        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);

        }

        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
