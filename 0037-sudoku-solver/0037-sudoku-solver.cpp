class Solution {
public:
    bool possible(int i, int j, vector<vector<char>>&board, char c){
        for(int n =0;n<9;n++){
            if(board[i][n]==c){
                return false;
            }
            if(board[n][j]==c){
                return false;
            }
            if(board[3*(i/3)+ n/3][3*(j/3)+ n%3]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(possible(i,j,board, c)){
                            board[i][j]=c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};