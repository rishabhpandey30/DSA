class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int cls_sum= INT_MAX/2;
        sort(nums.begin(), nums.end());
        int n= nums.size();

        for(int i=0; i<n-2; i++){
            int left=i+1;
            int right=n-1;
           
            while(left < right){
                 int ans= nums[i] + nums[left] + nums[right];
                
                
                if(abs(ans-target) < abs(cls_sum-target)){
                    cls_sum = ans;
                }
                if(ans == target){
                return ans;
                }

                else if( ans < target){
                left++;
                }
                
                else{
                right--;
                }
            }

        }
        return cls_sum; 
    }
};