class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    string rowkey="row"+to_string(i)+board[i][j];
                    string colkey="col"+to_string(j)+board[i][j];
                    string boxkey="box"+to_string((i/3)*3+(j/3))+board[i][j];

                    if(!seen.insert(rowkey).second) return false;
                    if(!seen.insert(colkey).second) return false;
                    if(!seen.insert(boxkey).second) return false;
                }
            }
        }
        return true;
    }
};