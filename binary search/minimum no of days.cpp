tc-o(n*(log(maxi-mini+1))
sc 0(1)

class Solution {
public:
int canmakebouquet(vector<int>& bloomDay, int day, int k){
    int bouquetcount=0; 
    int consecutive_count=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            consecutive_count++;
        }
        else{
            consecutive_count=0;
        }
        if(consecutive_count==k){
            bouquetcount++;
            consecutive_count=0;
        }
    }
    return bouquetcount;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
      int n=bloomDay.size();
      int start=0 ;
      int end= *max_element(bloomDay.begin(),bloomDay.end());

      int minidays=-1;
      while(start<=end){
        int mid=start+(end-start)/2;

        if(canmakebouquet(bloomDay,mid,k)>=m){
            minidays=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
      }
      return minidays;
    }
};
