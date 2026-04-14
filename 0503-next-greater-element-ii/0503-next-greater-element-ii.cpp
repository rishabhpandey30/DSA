class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=(2*n)-1;i>=0;i--){
            int j = i%n;
            while(!st.empty() && st.top() <= nums[j] ){
                st.pop();
            }
            if(i<n){
                if(st.empty()){
                    ans[i]= -1;
                }
                else{
                    ans[i]= st.top();
                }
            }
            st.push(nums[j]);
        }
        return ans;
    }
};