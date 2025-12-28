class Solution {
public:
    void create(vector<int>& nums, vector<int> ds, vector<vector<int>>& ans, int feq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!feq[i]){
                ds.push_back(nums[i]);
                feq[i]=1;
                create(nums,ds,ans,feq);
                ds.pop_back();
                feq[i]=0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int feq[nums.size()];
        for(int i=0;i<nums.size();i++){
            feq[i]=0;
        }
            create(nums,ds, ans,feq);
            return ans;
    }
};