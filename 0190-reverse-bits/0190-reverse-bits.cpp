class Solution {
public:
    int reverseBits(int n) {
        int ans =0;
        if(n==0){
            return ans;
        }
        for(int i=1;i<32;i++){
            int bit = n & 1;  // last bit extract
            n = n>>1;           // right shift 110 -> 11 to shift the bit
            ans = (ans | bit ) << 1;
        }
        return ans;

    }
};