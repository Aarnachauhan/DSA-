


class Solution {
public:
vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
bool find(vector<vector<char>> & board, int i , int j , string&word ,int ind){
if(ind==word.length()) return true;
if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$'){
return false;
}
if(board[i][j]!=word[ind]) return false;
char temp=board[i][j];
board[i][j]='$';
for(auto &d : dir){
    int ni=i+d[0];
    int nj=j+d[1];
    if(find(board,ni,nj,word,ind+1)) return true;
}
board[i][j]=temp;

return false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};
