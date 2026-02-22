class Solution {
public:
    int binaryGap(int n) {
        int gap =-1;
        int maxGap =-1;
        if(n==1){
            return 0;
        }
        n >>= __builtin_ctz(n);
        while(n>0){
            if(n & 1){
                maxGap = max(maxGap,gap);
                gap =0;
            }
            else{
                gap++;
            }
            n =n>>1;
        }
        return maxGap+1;
    }
};