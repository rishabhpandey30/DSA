class Solution {
public:
    long long posible(int mid, vector<int>&piles, int h){
        long long count =0;
        for(int i =0;i<piles.size();i++){
            count+= ((piles[i] -1)/mid) +1;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int l =1;
        int r = 0;
        for(int i=0;i<piles.size();i++){
            r = max(r, piles[i]);
        }
        while(l<=r){
            int mid = l + (r-l)/2;
            if(posible(mid,piles,h) <= h){
                ans = mid;
                r= mid -1;
            }
            else{
                l = mid +1;
            }
        }
        return ans;
    }
};