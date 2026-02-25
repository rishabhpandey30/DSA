class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int a=0;
        int b=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                a = nums[i];
                break;
            }
        }

        b= a;
        for(int i=1;i<=nums.size();i++){
            b ^= (nums[i-1]^ i);
        }
        return {a,b};
    }
};