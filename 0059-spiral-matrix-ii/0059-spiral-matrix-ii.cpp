class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top =0;
        int left =0;
        int bottom = n-1;
        int right =n-1;
        int num=1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans[top][i] = num++;
            }
            top++;
            
            for(int i=top;i<=bottom;i++){
                ans[i][right]=num++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=num++;
                }
            bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=num++;
                }
                left ++;
            }
        }
        return ans;
    }
};