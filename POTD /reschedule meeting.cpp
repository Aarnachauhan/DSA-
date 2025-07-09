lc 3439
tc-o(N)
sc-o(size of gap vector)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gap;
        gap.push_back(startTime[0]);

        for(int i=1;i<startTime.size();i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }
        gap.push_back(eventTime-endTime[endTime.size()-1]);

        //sliding window
        int i=0;
        int j=0;
        int maxsum=0;
        int cursum=0;

        int n=gap.size();
        while(j<n){
            cursum+=gap[j];
            if(i<n && j-i+1>k+1){
              cursum-=gap[i];
              i++;
            }
            maxsum=max(maxsum,cursum);
            j++;
        }
        return maxsum;
    }
};
