class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        for(int i=0;i<text.size();i++){
            mp[text[i]]++;
        }
        mp['l'] = mp['l'] /2;
        mp['o'] = mp['o'] /2;
        int ans = INT_MAX;
        string word = "balloon";
        for(int i=0;i<word.size();i++){
            ans = min(ans,mp[word[i]]);
        }
        return ans;
    }
};