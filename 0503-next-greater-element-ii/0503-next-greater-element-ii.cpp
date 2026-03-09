class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);
        stack<int> st;
        for(int i=(2*nums.size()) -1 ;i>=0;i--){
            int n = i % nums.size();
            while(!st.empty() && st.top() <= nums[n]){
                st.pop();
            }
            if(i<nums.size()){
                if(st.empty()){
                    ans[i] =-1;
                }
                else{
                ans[i]=st.top();
                }
            }
            st.push(nums[n]);
        }
        return ans;
    }
};