class Solution {
public:
    double myPow(double x, int n) {
        // double ans =1.0;
        // long nn=n;
        // if(n<0){
        //     nn = -1*nn;
        // }
        // while(nn>0){
        //     if(nn%2==1){
        //         ans = ans*x;
        //         nn = nn-1;
        //     }
        //     else{
        //         x = x*x;
        //         nn= nn/2;
        //     }
        // }
        // if(n<0){
        //     ans = (double)1.0/ans;
        // }
        // return ans;

        // With Recursion
         if (n == 0) return 1.0;
        long long nn=n;
        // Handle negative powers
        if (n < 0) {
            x = 1 / x;
            nn= -1*nn;
        }

        // Recursive step (divide and conquer)
        double half = myPow(x, nn / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};