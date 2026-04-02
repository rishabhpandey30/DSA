class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int ans = 0;

        while (n) {
            ans += num % (n % 10) == 0;
            n /= 10;
        }

        return ans;
    }
};