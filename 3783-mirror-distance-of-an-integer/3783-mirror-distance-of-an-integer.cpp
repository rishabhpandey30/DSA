class Solution {
public:
    int mirrorDistance(int n) {
        int n2=n;
        int n1 =0;
        while(n!=0){
            int digit = n%10;
            n1 = (n1*10) + digit;
            n = n/10;
        }
        int ans = abs(n2 -n1);
        return ans;
    }
};