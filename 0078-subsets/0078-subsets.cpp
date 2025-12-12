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
        // vector<vector<int>> ans;
        // vector<int> subset;
        //  create(ans,nums,0,subset);
        // return ans;

        //bit power set
        int n = nums.size();
        int subset = 1 << n;                 // total subsets = 2^n
        vector<vector<int>> ans;

        for(int num = 0; num < subset; num++){   // each mask from 0 to 2^n-1
            vector<int> list;

            for(int i = 0; i < n; i++){
                // Check if the i-th bit is set in the current mask
                if(num & (1 << i))              
                    list.push_back(nums[i]);     // If set, include the element
            }

            ans.push_back(list);                 // add subset to answer
        }
        return ans;
    }
};