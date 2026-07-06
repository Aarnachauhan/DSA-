lc 151
tc-O(n) , as both for and while loop is updating the same i
sc-o(n)


class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";

        reverse(s.begin(),s.end());

        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
             reverse(word.begin(),word.end());
        if(word.length()>0){
            ans+=" "+ word;
        }

        }
         return ans.substr(1);
       
    }
};


tc-o(n)
sc-o(n)
class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        reverse(s.begin(),s.end());

        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            } 
            reverse(word.begin(),word.end());
            if(word.length()>0){
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};


s = "the sky is blue"
Step 1: Initial values
s = "the sky is blue"
n = 15
ans = ""
Indexes of original s:

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
t h e   s k y   i s   b  l  u  e
Step 2: Reverse the whole string
reverse(s.begin(), s.end());
Now:

s = "eulb si yks eht"
Index mapping:

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
e u l b   s i   y k  s   e  h  t
Step 3: Start the for loop
🔹 Iteration 1: i = 0
word = ""
while loop:
i=0 → 'e' → word="e"
i=1 → 'u' → word="eu"
i=2 → 'l' → word="eul"
i=3 → 'b' → word="eulb"
i=4 → ' ' → stop
Now:

word = "eulb"
Reverse the word:

reverse(word.begin(), word.end());
word = "blue"
Append to ans:

ans = " blue"
🔹 Iteration 2: i = 4 (space)
while doesn’t run (space encountered)

word = ""
Nothing added to ans.

🔹 Iteration 3: i = 5
word = ""
while loop:
i=5 → 's' → word="s"
i=6 → 'i' → word="si"
i=7 → ' ' → stop
Reverse:

word = "is"
Append:

ans = " blue is"
🔹 Iteration 4: i = 7 (space)
Skip.

🔹 Iteration 5: i = 8
word = ""
while loop:
i=8  → 'y' → word="y"
i=9  → 'k' → word="yk"
i=10 → 's' → word="yks"
i=11 → ' ' → stop
Reverse:

word = "sky"
Append:

ans = " blue is sky"
🔹 Iteration 6: i = 11 (space)
Skip.

🔹 Iteration 7: i = 12
word = ""


optimised approach ( sc-o(1)
    
