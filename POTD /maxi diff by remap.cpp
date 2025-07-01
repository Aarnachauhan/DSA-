leetcode 2566

tc-o(n)
sc-o(1)
class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string maxi="";
        string mini="";
        int n=str.size();
        char ele=' ';
        //find first non-9 digit 
        for(int i=0;i<n;i++){
            if(str[i]!='9'){
                ele=str[i];
                break;
            }
        }
        //replace for max
        for(int i=0;i<n;i++){
            if(ele==str[i]) maxi+='9';
            else maxi+=str[i];
        }
        //replace for min
        for(int i=0;i<n;i++){
            if(str[0]== str[i]) mini+='0';
            else mini+=str[i];
        }
        //convert
        return stoi(maxi)-stoi(mini);

    }
};
