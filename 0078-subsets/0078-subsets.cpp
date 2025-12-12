class Solution {
public:
    void create(vector<vector<int>>& ans ,vector<int>&nums,int i,vector<int>&subset){
        if(i>=nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        create(ans,nums,i+1,subset);
        subset.pop_back();
        create(ans,nums,i+1,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
         create(ans,nums,0,subset);
        return ans;
    }
};