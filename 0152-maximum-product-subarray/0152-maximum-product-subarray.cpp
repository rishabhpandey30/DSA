class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n=nums.size();
       int maxi=INT_MIN;
       int p=1,s=1;

       for(int i=0;i<n;i++){
        if(p==0){
            p=1;
        }
        if(s==0){
            s=1;
        }
        p*=nums[i];
        s*=nums[n-1-i];
        maxi=max(maxi,max(s,p));

       }
       return maxi;
    }
};