class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>res;
        create(candidates, target, 0,0,ans,res);
        return ans;
    }

    void create(vector<int>& candidates, int target, int idx, int total, vector<vector<int>>& ans, vector<int>&res){
        if(total == target){
            ans.push_back(res);
            return;
        }
        if(total > target || idx >= candidates.size()){
            return;
        }
        res.push_back(candidates[idx]);
        create(candidates, target, idx, total+candidates[idx], ans, res); // index isliye nhi bda rhe h kyu ki us element ko ham kitne baar bhi le sakte jase ki 2 ko 2 baar liya h
        res.pop_back();
        create(candidates, target, idx+1, total, ans, res);
    }
};