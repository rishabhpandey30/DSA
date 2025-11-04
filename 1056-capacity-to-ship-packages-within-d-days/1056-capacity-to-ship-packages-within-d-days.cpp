class Solution {
public:
    int loadday(vector<int>& weights,int mid){
        int day=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+ weights[i]> mid){
                sum=0;
                day++;
            }
                sum+=weights[i];
        }
        if(sum <= mid) {
            day++;
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s= *max_element(weights.begin(), weights.end());
        int e=0;
        for(int i=0;i<weights.size();i++){
            e+=weights[i];
        }
        int ans=0;
        int mid =s+(e-s)/2;
        while(s<=e){
            int d=loadday(weights,mid);
            if(d<=days){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid =s+(e-s)/2;
        }
        return ans;
    }
};