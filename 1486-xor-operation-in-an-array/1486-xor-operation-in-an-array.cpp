class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n],i=0,copy=n;
        while(n>0){
            nums[i]=start+2*i;
            i++;
            n--;
        }
        int j=1,res=nums[0];;
        while(copy>1){
            res^=nums[j];
            j++;
            copy--;
        }
        return res;
    }
};