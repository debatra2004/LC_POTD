class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char digit){
        //horizontal
        for(int j=0;j<9;j++){
            if(board[row][j]==digit) return false;
        }
        //vertical
        for(int i=0;i<9;i++){
            if(board[i][col]==digit) return false;
        }
        //3x3 grid
        int gridr=(row/3)*3;
        int gridc=(col/3)*3;
        for(int i=gridr;i<=gridr+2;i++){
            for(int j=gridc;j<=gridc+2;j++){
                if(board[i][j]==digit) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        int nextr=row;
        int nextc=col+1;
        if(nextc==9){
            nextr=row+1;
            nextc=0;
        }
        if(board[row][col]!='.') return helper(board,nextr,nextc);
        for(char dig='1';dig<='9';dig++){
            if(issafe(board,row,col,dig)){
                board[row][col]=dig;
                if(helper(board,nextr,nextc)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};