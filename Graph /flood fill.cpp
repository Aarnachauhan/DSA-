leetcode 733


class Solution {
public:
void dfs(int row , int col , vector<vector<int>> &ans, vector<vector<int>>& image , int newcolor , int inicolor ){
 int n=image.size();
 int m=image[0].size();

 ans[row][col]=newcolor;
 int drow[]={-1,0,1,0};
 int dcol[]={0,-1,0,1};

 for(int i=0;i<4;i++){
    int nrow=row+drow[i];
    int ncol=col+dcol[i];

    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
        dfs(nrow,ncol , ans, image,newcolor,inicolor);
    }
 }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;

        dfs(sr,sc,ans,image,color,inicolor);

        return ans;
    }
};
