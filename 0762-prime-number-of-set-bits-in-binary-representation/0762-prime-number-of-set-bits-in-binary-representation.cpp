class Solution {
public:
    bool prime(int val){
        int count =0;
        if(val<2){
            return false;
        }
        for(int i=2;i<val;i++){
            if(val%i==0){
                return false;
            }
        }
        return true;
    }
    int countSetBit(int num){
       
        int count=0;
        while(num!=0){
            int val = num & 1;
            if(val ==1){
                count++;
            }
            num = num >> 1;
        }
        return count;


        // Brian Kernighan Algorithm  -> use to count the set bit
        // while(n){
        //  n = n & (n - 1);
        // count++;
        // }

    }

    int countPrimeSetBits(int left, int right) {
        int ans =0;
        for(int i = left ;i<=right;i++){
            int val = countSetBit(i);
            if(prime(val)){
                ans++;
            }
        }
        return ans;
    }
};