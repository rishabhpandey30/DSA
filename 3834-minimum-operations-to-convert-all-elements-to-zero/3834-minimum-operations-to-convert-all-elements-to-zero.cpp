class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        int op=0;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top() > nums[i]){
                st.pop();
            }
            if(nums[i]==0){
                continue;
            }
            if(st.empty() || st.top()<nums[i]){
                op++;
                st.push(nums[i]);
            }
        }
        return op;
    }
};