tc-o(n)
sc-o(1)

class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;

        int v=0;
        int con=0;
        string vowels="aeiouAEIOU";
        for(char c: word){
            if(isalpha(c)){
                if(vowels.find(c)!=string::npos){
                  v++;
                }else con++;
            }
            else if(!isdigit(c)){
                return false ; //special character 
            }
        }
        return v>=1 && con>=1;
    }
};
w/t built in function 
class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;
        bool vowel=false , con=false;
        for(int i=0;i<n;i++){
            if(word[i]=='@' || word[i]=='#' || word[i]=='$') {
                return false;
            }
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o'
            || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U'){
                vowel=true;
            }
        else if( (word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')) 
               con = true;
        }
                    
        if(vowel == true && con == true) return true;
        return false;  
        }
    
};
