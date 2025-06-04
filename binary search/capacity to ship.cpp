leetcode
Complexity
Time complexity:
O((log(max element-totalsum)+1)*(n))

Space complexity:
O(1)

class Solution {
public:
 int finddays(vector<int> &weights,int capacity){
   int day=1;
   int load=0;
   int n=weights.size();
   for(int i=0;i<n;i++){  //O(n)
    if(weights[i]+load>capacity){
        day+=1;
        load=weights[i];
    }else{
        load+=weights[i];
    }
   
   }
  return day;
 }


    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        while(low<=high){ //O(log(max element - total weight)+1)
            int mid=(low+high)/2;
            int noofdays=finddays(weights,mid);
            if(noofdays<=days){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};
