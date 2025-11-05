class Solution {
public:
  long long sumof(vector<int>&nums, int mid ,int k){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= (long long)(nums[i]+mid-1) / mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        int s=1;
        int e= *max_element(nums.begin(),nums.end());
        int ans=0;
        int mid = s+(e-s)/2;
        while(s<=e){
            long long sum =sumof(nums,mid,k);
            if(sum<=k){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};
