class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
         vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int val = nums[i];
            while (val > 0) {
                ans.push_back(val % 10);
                val /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};