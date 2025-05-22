#include <bits/stdc++.h>
using namespace std;



int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) {
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                
                cnt=0;
            }
        }
        return maxi;
    }
int main(){
    int a[]={1,1,0,1,1,1};
    int n=sizeof(a)/sizeof(a[0]);
    int max=consecutive(a,n);
    cout<<max;
    return 0;
}
