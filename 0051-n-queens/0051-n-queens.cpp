class Solution {
public: 
    // approch 1 (without hashing)
    // bool possible(vector<string>& board,int row, int col,int n){
    //     // upper diagonal
    //     int c =col;
    //     int r =row;
    //     while(c>=0 && r >= 0){
    //         if(board[r][c]=='Q'){
    //             return false;
    //         }
    //         c--;
    //         r--;
    //     }
    //     //left side
    //     c= col;
    //     r= row;
    //     while(c>=0){
    //         if(board[r][c]=='Q'){
    //             return false;
    //         }
    //         c--;
    //     }
    //     //lower diagnol
    //     r = row;
    //     c= col;
    //     while(r<n && c>=0){
    //         if(board[r][c]=='Q'){
    //             return false;
    //         }
    //         r++;
    //         c--;
    //     }
    //     return true;
    // }
    // void create(vector<string>& board, int col, int n, vector<vector<string>>& ans){
    //     if(col == n){
    //         ans.push_back(board);
    //         return;
    //     }
    //     for(int row =0;row<n;row++){
    //         if(possible(board, row, col,n)){
    //             board[row][col]='Q';
    //             create(board, col+1, n  ,ans);
    //             board[row][col]='.';
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>ans;
    //     vector<string> board(n); // vector of string
    //     string s(n,'.'); // string of '.' eg -> '....',  n=4
    //     for(int i=0;i<n;i++){
    //         board[i]=s;  //vector of 4 size having the string '....' when n=4 i.e ['....',3 more]
    //     }
    //     create(board, 0,n, ans);
    //     return ans;
    // }

    // Approch 2(hashing)
     void create(vector<string>& board, int col, int n, vector<vector<string>>& ans,vector<int>&left,vector<int>&lowerD ,vector<int>&upperD){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row =0;row<n;row++){
            if(left[row]==0 && lowerD[row+col]==0 && upperD[(n-1)+(col-row)]==0){

                // change and mark
                board[row][col]='Q';
                left[row]=1;
                lowerD[row+col]=1;
                upperD[(n-1)+(col-row)]=1;

                create(board, col+1, n  ,ans,left, lowerD, upperD);

                //undo
                board[row][col]='.';
                left[row]=0;
                lowerD[row+col]=0;
                upperD[(n-1)+(col-row)]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.'); 
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>left(n,0);
        vector<int>lowerD((2*n)-1, 0);
        vector<int>upperD((2*n)-1, 0);
        create(board, 0,n, ans,left, lowerD, upperD);
        return ans;
    }
};