class Solution {
public:
    int trap(vector<int>& height) {
        // using prefixMax and SufixMax (two pointers)
        int n = height.size();
        int total =0;
        vector<int>sufixMax(n,0);
        sufixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            sufixMax[i] = max(sufixMax[i+1], height[i]);
        }
        int left = height[0];
        int right = sufixMax[n-1];
        for(int i=0;i<n;i++){
            left = max(left, height[i]);
            right = sufixMax[i];
            if(left > height[i] && right > height[i]){
                total += min(left,right) - height[i];
            }
        }
        return total;
    }
};