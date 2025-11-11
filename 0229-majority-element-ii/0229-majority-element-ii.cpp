class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         // map<int ,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // int ans=0;
        // int n=nums.size();
        // nums={};
        // for(auto it : mp){
        //     if(it.second > n/3){
        //         nums.push_back(it.first);
        //     }
        // }
        // return nums;

        int count1=0, count2=0;
        int el1, el2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && el2!= nums[i]){
                count1=1;
                el1=nums[i];
            }
            else if(count2==0 && el1!= nums[i]){
                count2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1){
                count1++;
            }
            else if(nums[i]==el2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int c1=0;int c2=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]){
                c1++;
            }
            if(el2==nums[i]){
                c2++;
            }
        }
        nums={};
        if(c1>n/3){
            nums.push_back(el1);
        }
        if(c2>n/3){
            nums.push_back(el2);
        }
        return nums;
    }
};