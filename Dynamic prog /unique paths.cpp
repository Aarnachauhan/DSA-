leetcode 

recursion--->
tc- O(2^m*n)
sc-O(path length) = O(m-1) + (n-1)


class Solution {
public:
int rec(int i,int j, int m , int n){
    if(i==0 && j==0) return 1;
    if(i<0 && j<0) return 0;

    //move up 
    int up=rec(i-1,j,m,n);

    //move left 
    int left=rec(i,j-1,m,n);
    return up + left;
}
    int uniquePaths(int m, int n) {
        return rec(0,0,m,n);
    }
};

memorization --->
  
