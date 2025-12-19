class Solution {
public:
    void create(vector<int>& nums,int i, vector<vector<int>>& ans,vector<int>& subset ){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
        
            subset.push_back(nums[i]);
            create(nums,i+1,ans,subset);
            subset.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
            create(nums,i+1,ans,subset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>subset;
        sort(nums.begin(), nums.end());
        create(nums, 0, ans, subset);
        return ans;
   }
};