class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Brute Force
        // int n = nums.size();
        // long long totalSum =
        //     accumulate(nums.begin(), nums.end(), 0LL);  // Use long long for sum

        // // If the total sum is already divisible by p, no subarray needs to be
        // // removed
        // if (totalSum % p == 0) return 0;

        // int minLen = n;  // Initialize minLen to the size of the array

        // // Try removing every possible subarray
        // for (int start = 0; start < n; ++start) {
        //     long long subSum = 0;  // Use long long to avoid overflow
        //     for (int end = start; end < n; ++end) {
        //         subSum += nums[end];  // Calculate the subarray sum

        //         // Check if removing this subarray makes the remaining sum
        //         // divisible by p
        //         long long remainingSum = (totalSum - subSum) % p;

        //         if (remainingSum == 0) {
        //             minLen = min(minLen,
        //                          end - start +
        //                              1);  // Update the smallest subarray length
        //         }
        //     }
        // }

        // // If no valid subarray is found, return -1
        // return minLen == n ? -1 : minLen;

        // Prefix Sum
        int n = nums.size();
        int totalSum = 0;

        // Step 1: Calculate total sum and target remainder
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        int target = totalSum % p;
        if (target == 0) return 0;  // The array is already divisible by p

        // Step 2: Use a hash map to track prefix sum mod p
        unordered_map<int, int> modMap;
        modMap[0] =
            -1;  // To handle the case where the whole prefix is the answer
        int currentSum = 0, minLen = n;

        // Step 3: Iterate over the array
        for (int i = 0; i < n; ++i) {
            currentSum = (currentSum + nums[i]) % p;

            // Calculate what we need to remove
            int needed = (currentSum - target + p) % p;

            // If we have seen the needed remainder, we can consider this
            // subarray
            if (modMap.find(needed) != modMap.end()) {
                minLen = min(minLen, i - modMap[needed]);
            }

            // Store the current remainder and index
            modMap[currentSum] = i;
        }

        // Step 4: Return result
        return minLen == n ? -1 : minLen;
    }
};