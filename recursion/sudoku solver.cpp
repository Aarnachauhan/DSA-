lc 37

class Solution {
public:
bool isvalid(vector<vector<char>> & board , int row , int col , char d){
   for(int i=0;i<9;i++){
       if(board[i][col]==d) return false;
       if(board[row][i]==d) return false;
   }
   int startrow=row/3 * 3;
   int startcol=col/3*3;

   for(int k=0;k<3;k++){
    for(int l=0;l<3;l++){
        if(board[startrow+k][startcol+l]==d) return false;
    }
   }
   return true;
}
bool solve(vector<vector<char>> & board ){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
           if(board[i][j]=='.'){
            for(int d='1';d<='9';d++){
                if(isvalid(board,i,j,d)){
                    board[i][j]=d;
                    if(solve(board)) return true; //true then return from here only
                    board[i][j]='.'; //when false;
                }

            }
            return false;
           }
        }
    }
    return true; //all cells are already filled
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
