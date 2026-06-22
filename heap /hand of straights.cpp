lc 846

tc-o(nlogn)
sc-o(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        map<int,int> mpp;
        for(int card:hand){
            mpp[card]++;
        } 
        while(!mpp.empty()){
            int start=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                int card=start+i;

                if(mpp.find(card)==mpp.end()) return false;
                mpp[card]--;

                if(mpp[card]==0) mpp.erase(card);

            }
        }
        return true;
    }
};
