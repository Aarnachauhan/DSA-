lc 506


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedscore= score;
        sort(sortedscore.begin(),sortedscore.end(), greater<int>());
        vector<string> medals={"Gold Medal" , "Silver Medal" ,"Bronze Medal"};
        unordered_map<int,string> rankmapping;
        for(int i=0;i<sortedscore.size();i++){
          if(i<3){
            rankmapping[sortedscore[i]]=medals[i];
          }else{
            rankmapping[sortedscore[i]]= to_string(i+1);
          }
        }

        vector<string> res;
        for(int s: score){
            res.push_back(rankmapping[s]);
        }
        return res;
    }
};
