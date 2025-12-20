class Solution {
public:
    void create(int k, int n, int idx, int sum, vector<vector<int>>& ans, vector<int>& subset){
        if(k==0){
            if(sum==n){
                ans.push_back(subset);
                return;
            }
            else{
                return;
            }
        }
        if(idx>9){
            return;
        }
        //pick 
        subset.push_back(idx);
        sum +=idx;
        create(k-1,n,idx+1,sum,ans,subset);
        //backtract
        subset.pop_back();
        sum-=idx;
        //ignore
        create(k,n,idx+1,sum,ans,subset);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>subset;
        create(k,n,1,0,ans,subset);
        return ans;
    }
};