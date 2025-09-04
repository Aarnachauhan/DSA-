gfg

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int n=start.size();
        int rooms=0; int maxi=0;
        int i=0; int j=0; 
        while(i<n && j<n){
            if(start[i]<end[j]){ //need room
                rooms++;
                maxi=max(rooms,maxi);
                i++;
            }
            else {
                rooms--; //no need of room -> free ho gaya
                j++;
            }
        }
        return maxi;
        
    }
};
