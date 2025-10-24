leetcode 832
tc-o(n*n)
sc-o(1)

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++){
            int m=image[i].size();
            for(int j=0;j<m/2;j++){
                swap(image[i][j],image[i][m-1-j]);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<image[i].size();j++){
                if(image[i][j]==0) image[i][j]=1;
                else image[i][j]=0;
            }
        }
        return image;
    }
};
