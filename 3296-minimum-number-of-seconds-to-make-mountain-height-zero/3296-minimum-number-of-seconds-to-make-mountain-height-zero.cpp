class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& t) {
        long long l = 1, r = 1e18, ans = r;

        while(l <= r){
            long long mid = (l + r) / 2;

            long long tot = 0;

            for(int x : t){
                long long val = (2 * mid) / x;
                long long k = (sqrt(1 + 4 * val) - 1) / 2;
                tot += k;

                if(tot >= h) break;
            }

            if(tot >= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};