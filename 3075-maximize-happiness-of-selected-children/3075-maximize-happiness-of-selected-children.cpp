class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int count =0;
        long long sum =0;
        for(int i=happiness.size()-1;i>=0;i--){
            if(count>=k){
                break;
            }
            int a = happiness[i]-count;
            if(a<0){
                sum+=0;
            }
            else{
            sum+=a;
            }
            count++;
        }
        return sum;
    }
};