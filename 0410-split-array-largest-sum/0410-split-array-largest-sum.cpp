class Solution {
public:
    int splitt(vector<int>&nums, int mid, int k){
        int sum=0;
        int st=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                sum=0;
                st++;
            }
            sum+=nums[i];
        }
        return st;
    }
    int splitArray(vector<int>& nums, int k) {
       int s=*max_element(nums.begin(),nums.end());
       int e=0;
       for(int i=0;i<nums.size();i++){
        e+=nums[i];
       } 
       int ans=-1;
       while(s<=e){
        int mid=s+(e-s)/2;
        int st=splitt(nums,mid,k);
        if(st<=k){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
       }
       return ans;
    }
};
