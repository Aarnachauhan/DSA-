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
