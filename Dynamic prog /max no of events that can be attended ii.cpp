leetcode 1751

recursion :
time limit exceeded
class Solution {
public:
int n;
int solve(vector<vector<int>> &events, int i,int k){
    if(i>=n || k==0) return 0;
    int start=events[i][0];
    int end=events[i][1];
    int value=events[i][2];

    int skip=solve(events, i+1 , k);
    int j=i+1;
    for( j=i+1;j<n;j++){
        if(events[j][0]>events[i][1]){
            break;
        }
    }
    int take=value + solve(events, j, k-1);
    return max(take,skip);
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        n=events.size();
        return solve(events, 0,k );
    }
};


memorization:
