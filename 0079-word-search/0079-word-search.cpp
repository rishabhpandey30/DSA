class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word){
        int n = board.size();
        int m= board[0].size();
        if(idx == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$'){   // $ means visited 
            return false;
        }
        if(board[i][j] != word[idx]){
            return false;
        }
        char temp = board[i][j]; // storing the real value
        board[i][j]= '$';   // visited
        if(find(board,i+1,j,idx+1,word) || find(board,i-1,j,idx+1,word)|| find(board,i,j+1,idx+1,word) || find(board,i,j-1,idx+1,word)){   // checking the left, right and up, down value
            return true;
        }
        board[i][j]=temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m= board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && find(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};