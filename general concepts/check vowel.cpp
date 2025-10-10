leetcode 345
class Solution {
public:
bool isvowel(char c){
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
    string reverseVowels(string s) {
        int len=s.length();
        int l=0;
        int r=len-1;
        while(l<r){
            if(isvowel(s[l]) && isvowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(!isvowel(s[l])) l++;
            else if(!isvowel(s[r])) r--;
        
       }
    return s;
    }
};
