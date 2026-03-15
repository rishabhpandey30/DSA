class Solution {
public:
    vector<int> findnsi(vector<int>& arr){
        vector<int>ans(arr.size(),0);
        stack<int> st;
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = arr.size();
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findpsi(vector<int>& arr){
        vector<int>ans(arr.size(),0);
        stack<int> st;
        for(int i = 0;i< arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int mod = pow(10,9) + 7;
        vector<int> nsi = findnsi(arr);
        vector<int> psi = findpsi(arr);
        for(int i=0;i<n;i++){
            int left = i - psi[i];
            int right = nsi[i] -i;
            sum = (sum + left*right*1LL*arr[i])%mod;
        }
        return sum;
    }
};