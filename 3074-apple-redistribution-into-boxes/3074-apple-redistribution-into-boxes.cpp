class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int ans = 0;
        int sum = 0;
        int count =0;
        int cap= 0;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
    int i=capacity.size()-1;
        sort(capacity.begin(), capacity.end());
        while(sum>0 && i>-1){
            sum -= capacity[i];
            count++;
            i--;
        }
        return count;
    }
};