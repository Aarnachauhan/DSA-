leetcode 3333


recursion - passed 704/846 
class Solution {
public:
int M = 1e9 +7 ;
int  solve(int i, int count , vector<int> freq, int k){
   if(i>=freq.size()){
    if(count<k){
        return 1;
    }else{
        return 0;
    }
   }
   long long result=0;
   
   for(int take=1;take<=freq[i];take++){
    if(count + take <k){
        result=(result + solve(i+1,count+take , freq, k)) % M;
    }else{
        break;
    }
   }
   return result;
}
 
    int possibleStringCount(string word, int k) {
        if(k>word.length()){
            return 0; //no possible answer return 0
        }

        vector<int> freq;
        int n=word.length();
        int count=1;
        for(int i=1;i<n;i++){
           if(word[i-1]==word[i]) count++;
           else {
            freq.push_back(count);
            count=1;
           }

        }
        freq.push_back(count); //last wale ka count 

        int p=1; 
        for(int &f: freq){
            p=(p*f) % M; //total possibilities
        }
        if(freq.size()>=k) return p; //all possibilities are valid

        //we have to find invalid counts
        long long invalidcount=solve(0,0,freq,k);
        return (p-invalidcount);

    }
};
