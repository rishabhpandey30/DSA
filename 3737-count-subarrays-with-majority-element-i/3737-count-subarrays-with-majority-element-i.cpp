class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dresaniel = nums;  

        int count = 0;

        for (int i = 0; i < n; i++) {
            int balance = 0; 
            for (int j = i; j < n; j++) {
                if (nums[j] == target)
                    balance++; 
                else
                    balance--;

                if (balance > 0)
                    count++;
            }
        }

        return count;
    }
};