class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        int b=1;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                v[a]=nums[i];
                a=a+2;
            }
            else{
                v[b]=nums[i];
                b=b+2;
            }
        }
        return v;
    }
};