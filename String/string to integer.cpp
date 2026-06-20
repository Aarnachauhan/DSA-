lc 8
class Solution {
public:
    int myAtoi(string s) {
        int j = 0;
        int sign = 1;
        int n = s.length();
        
        // 1. Skip spaces
        while(j < n && s[j] == ' ') j++;
        
        // 2. Handle sign cleanly and move the pointer forward!
        if (j < n && (s[j] == '+' || s[j] == '-')) {
            if (s[j] == '-') sign = -1;
            j++; // Crucial: move past the sign character
        }
        
        int ans = 0;
        // 3. Process digits
        while(j < n && s[j] >= '0' && s[j] <= '9'){
            int digit = s[j] - '0';
            
            // Look ahead to check for overflow BEFORE updating ans
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            j++;
        }
        
        return sign * ans;
    }
};
