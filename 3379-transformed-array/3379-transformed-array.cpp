class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>r(n,0);
        for(int i=0;i<nums.size();i++){
            int shift = nums[i]%n;
            int newIdx = (i+ shift)%n;
            if(newIdx < 0){
                newIdx +=n;
            }
            r[i] = nums[newIdx];
        }
        return r;
    }
};