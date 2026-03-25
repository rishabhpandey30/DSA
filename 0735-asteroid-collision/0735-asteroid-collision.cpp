class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]> 0){
                ans.push_back(asteroids[i]);
            }
            else{
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])){
                    ans.pop_back();
                }
                if(!ans.empty() && ans.back() == abs(asteroids[i])){
                    ans.pop_back();
                }
                else if(ans.empty() || ans.back() < 0){
                    ans.push_back(asteroids[i]);
                }
        }
        }
        return ans;
    }
};