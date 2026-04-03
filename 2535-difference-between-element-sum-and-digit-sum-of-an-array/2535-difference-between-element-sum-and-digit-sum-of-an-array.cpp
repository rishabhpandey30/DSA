class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        int digit =0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            int n =nums[i];
            while(n){
                digit+= (n%10);
                n=n/10;
            }
        }
        return abs(sum-digit);
    }
};