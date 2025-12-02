class Solution {
public:
    int c=0;
    void merge(vector<int>&nums, int low ,int mid , int high){
        int left =low;
        int right = mid+1;
        vector<int>temp;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
           
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
             temp.push_back(nums[left]);
                left++;
        }
        while(right<=high){
              temp.push_back(nums[right]);
                right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    void count(vector<int>&nums, int low , int mid, int high){
        int right= mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]> 2*(long long)nums[right]){
                right++;
            }
            c+=(right-(mid+1));
        }
    }
    void ms(vector<int>& nums, int low, int high){
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        ms(nums,low,mid);
        ms(nums,mid+1,high);
        count(nums, low, mid,high);
        merge(nums,low, mid , high);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size()-1;
        ms(nums, 0, n);
        return c; 
    }
};