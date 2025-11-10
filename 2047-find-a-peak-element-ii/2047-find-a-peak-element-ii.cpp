class Solution {
public:
    int maxel(vector<vector<int>>& mat,int mid){
        int n=mat.size();
        int m=mat[0].size();
        int maxi=-1;
        int index=0;
        for(int i=0;i<n;i++){
           if(mat[i][mid]>maxi){
            index=i;
            maxi=mat[i][mid];
           }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high =mat[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=maxel(mat,mid);
            int left= mid -1 > 0 ? mat[row][mid-1] : -1;
            int right =mid+1 < mat[0].size() ? mat[row][mid+1] : -1;
            if(left<mat[row][mid] && right<mat[row][mid]){
                return {row ,mid};
            }
           else if(mat[row][mid]<left){
            high=mid-1;
           }
           else{
            low=mid+1;
           }
        }
        return {-1, -1};
    }
};