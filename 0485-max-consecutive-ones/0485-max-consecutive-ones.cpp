class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // int res = 0;
        // int left = 0;
        // for (int right = 0; right < nums.size(); right++) {
        //     if (nums[right] == 0) {
        //         left = right + 1;
        //     } else {
        //         res = max(res, right - left + 1);
        //     }
        // }

        // return res;

        int n=nums.size();
        int count=0;
        int maxi=count;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count=0;
            }
            else{
                count++;
                maxi=max(count,maxi);
            }
        }
        return maxi;
    }

};