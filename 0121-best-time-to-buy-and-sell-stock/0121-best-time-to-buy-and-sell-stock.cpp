class Solution {
public:
    int maxProfit(vector<int>& nums) {
        //    int min=nums[0];
    //    int maxi=0;
    //    for(int i=0;i<nums.size();i++){
    //     if(min>nums[i]){
    //         min=nums[i];
    //     }
    //     int a=nums[i]-min;
    //     maxi=max(a,maxi);
    //    }
    //    return maxi;
   
    int min=nums[0];
    int maxi=0;
    for(int i=1;i<nums.size();i++){
        if(min>nums[i]){
            min=nums[i];
        }
        int a=nums[i]-min;
        maxi=max(maxi,a);
    }
return maxi;
    }
};