class Solution {
public:
    int maxArea(vector<int>& arr) {
       int ans =0;
       int l = 0;
       int r =arr.size()-1;
       while(l<r){
        int w = abs(r-l);
        int h = min(arr[l], arr[r]);
        if(arr[l]>arr[r]){
            r--;
        }
        else{
            l++;
        }
        ans = max(ans, w*h);
       }
       return ans;
    }
};