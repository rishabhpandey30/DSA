class Solution {
public:
    int trap(vector<int>& height) {
        // using prefixMax and SufixMax (two pointers)
        // int n = height.size();
        // int total =0;
        // vector<int>sufixMax(n,0);
        // sufixMax[n-1] = height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     sufixMax[i] = max(sufixMax[i+1], height[i]);
        // }
        // int left = height[0];
        // int right = sufixMax[n-1];
        // for(int i=0;i<n;i++){
        //     left = max(left, height[i]);
        //     right = sufixMax[i];
        //     if(left > height[i] && right > height[i]){
        //         total += min(left,right) - height[i];
        //     }
        // }
        // return total;


        // using two pointers (reduces the space complexity)
        int left =0;
        int right = height.size()-1;
        int leftMax = 0;
        int rightMax =0;
        int total = 0;
        while(left<right){
            if(height[left] <= height[right]){
                if(leftMax > height[left]){
                    total += leftMax - height[left];
                }
                else{
                    leftMax = height[left];
                }
                left++;
            }
            else{
                if(rightMax > height[right]){
                    total += rightMax - height[right];
                }
                else{
                    rightMax = height[right];
                }
                right--;
            }
        }
        return total++;
    }
};