class Solution {
public:
    void create(vector<int>&candidates, int target, int idx, int total, vector<vector<int>>& ans , vector<int>& sub){
        if(total == target){ 
            ans.push_back(sub);
            return;
        }
        if(total > target || idx>= candidates.size()){
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target < candidates[i]){
                break;
            }
        sub.push_back(candidates[i]);
        create(candidates, target, i+1, total+ candidates[i], ans, sub);
        sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        create(candidates, target, 0, 0, ans, sub);
        return ans;
    }
};