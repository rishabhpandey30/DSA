class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit = 0;
        int buystock = nums[0];
        for(int i=0;i<nums.size();i++){
            buystock = min(buystock, nums[i]);
            profit = max(profit, nums[i] - buystock );
        }
        return profit;
    }
};