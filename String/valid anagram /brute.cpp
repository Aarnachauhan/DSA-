class Solution {
    public boolean isAnagram(String s1, String s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};
