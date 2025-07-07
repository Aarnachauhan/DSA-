leetcode 1353
key concept:
vector<vector<int>> events = {
    {1, 2},  // Event 1: can be attended on day 1 or 2
    {2, 3},  // Event 2: can be attended on day 2 or 3
    {3, 4}   // Event 3: can be attended on day 3 or 4
};
Here:

events[0][0] = 1, events[0][1] = 2

events[1][0] = 2, events[1][1] = 3

events[2][0] = 3, events[2][1] = 4

So:

events[i][0] → start day of event i

events[i][1] → end day of event i


-----------------------------------------------
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int day=events[0][0];
        int i=0;
        int count=0;
        priority_queue<int, vector<int>,greater<int>> pq;
        while(!pq.empty() || i<n){
            while(i<n && events[i][0]==day){ //starting = day
            pq.push(events[i][1]); //event ending day
            i++;
            }
            if(!pq.empty()){
                pq.pop();
                count++;
            }
            day++;
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return count;
    }
};
