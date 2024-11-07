largest combination with bitwise and greater than zero.
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> countarray(24,0); //sc-o(24)

        int result=0;
        for(int i=0;i<24;i++){ //tc-o(24)
            for(int &num: candidates){ //tc-o(n)
                if((num & (1<<i)) !=0){
                    countarray[i]++;
                }
            }
            result=max(result,countarray[i]);
        }
        return result;
    }
};

tc- o(n)
sc- o(24)
