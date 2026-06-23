lc 455
Time Complexity

Sorting students:

O(n log n)

Sorting cookies:

O(m log m)

Two-pointer traversal:

O(n+m)

Total:

O(n log n + m log m)


sc= o(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        while(l<n && r<m){
            if(g[l]<=s[r]){
               l++;
            }
            r++;
        }
        return l;
    }
};
