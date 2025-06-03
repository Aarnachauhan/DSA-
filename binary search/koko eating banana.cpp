leetcode
tc- O(N)*o(log(maxelement))


class Solution {
public:
int findmax(vector<int> &piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
     maxi=max(maxi,piles[i]);
    }
    return maxi;
}
long long caltotal(vector<int> &piles,int h){
   long long total=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            total+=ceil(  piles[i] / (double) h ); //int will not give proper ceil value
            //so we have to convert it to double
        }
        return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=findmax(piles);
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            long long total=caltotal(piles,mid);
            if(total<=h){ 
                ans=mid;
                e=mid-1; //aur choti value dhudho
            }else{
                s=mid+1;
            }
        }
    return ans; //s will first stand on a value which cant be an answer and then goes to answer
    //e will first stand on value which will be a answer but then goes to a value which cant.
    } 
};
