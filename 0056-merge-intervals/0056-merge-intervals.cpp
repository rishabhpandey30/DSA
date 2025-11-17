class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        //brute force
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<vector<int>> ans;
        // for(int i=0;i<n;i++){
        //     int start = nums[i][0];
        //     int end=nums[i][1];
        //     if(!ans.empty() && end<=ans.back()[1]){
        //         continue;
        //     }
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j][0]<=end){
        //             end=max(end, nums[j][1]);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     ans.push_back({start, end});
        // }
        // return ans;

        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(ans.empty() || nums[i][0]> ans.back()[1]){
                ans.push_back(nums[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1], nums[i][1]);
            }
        }
        return ans;
    }
};