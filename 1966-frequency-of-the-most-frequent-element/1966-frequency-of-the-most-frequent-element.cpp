class Solution {
public:
    // int binaryS(int i,int k,vector<int>& nums, vector<long>& Prefixsum ){
    //     int l=0;
    //     int r= i;
    //     int res = i;
    //     while(l<=r){
    //         int mid = l+(r-l)/2;
    //         long count = i - mid+1;
    //         long sum = count*nums[i];
    //         long currsum = Prefixsum[i]-Prefixsum[mid]+nums[mid];
    //         int freq= sum - currsum;
    //         if(freq>k){
    //             l=mid+1;
    //         }
    //         else{
    //             res= mid;
    //             r= mid -1;
    //         }
    //     }
    //     return i - res+1;
    // }
    int maxFrequency(vector<int>& nums, int k) {
        //Method 1 : 
        // int n= nums.size();
        // sort(nums.begin(), nums.end());
        // vector<long> Prefixsum(n);
        // Prefixsum[0]= nums[0];
        // for(int i=1;i<n;i++){
        //     Prefixsum[i] = Prefixsum[i-1]+nums[i];
        // }
        // int result =1;
        // for(int i=0;i<n;i++){
        //     int freq = binaryS(i,k,nums,Prefixsum);
        //     result = max(freq, result);
        // }
        // return result;

        // Method -2 : sliding window
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        
        return nums.size() - left;
    }
};