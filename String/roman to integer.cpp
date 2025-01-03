class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int> roman={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        
        };
        int n=s.size();
        for(int i=0;i<n-1;i++){
         if(roman[s[i]]<roman[s[i+1]]){
            res-=roman[s[i]];
         }else{
            res+=roman[s[i]];
         }
        }
        return res+ roman[s[n-1]];
    }
};
