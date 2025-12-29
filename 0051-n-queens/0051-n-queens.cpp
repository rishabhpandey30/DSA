class Solution {
public: 
    // approch 1 (without hashing)
    bool possible(vector<string>& board,int row, int col,int n){
        // upper diagonal
        int c =col;
        int r =row;
        while(c>=0 && r >= 0){
            if(board[r][c]=='Q'){
                return false;
            }
            c--;
            r--;
        }
        //left side
        c= col;
        r= row;
        while(c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            c--;
        }
        //lower diagnol
        r = row;
        c= col;
        while(r<n && c>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r++;
            c--;
        }
        return true;
    }
    void create(vector<string>& board, int col, int n, vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row =0;row<n;row++){
            if(possible(board, row, col,n)){
                board[row][col]='Q';
                create(board, col+1, n  ,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n); // vector of string
        string s(n,'.'); // string of '.' eg -> '....',  n=4
        for(int i=0;i<n;i++){
            board[i]=s;  //vector of 4 size having the string '....' when n=4 i.e ['....',3 more]
        }
        create(board, 0,n, ans);
        return ans;
    }
};