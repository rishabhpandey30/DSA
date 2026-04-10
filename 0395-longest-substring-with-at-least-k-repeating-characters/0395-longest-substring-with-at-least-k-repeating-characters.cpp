class Solution {
public:
    int longestSubstring(string s, int k) {
        int max_len = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]] < k){
                int left = longestSubstring(s.substr(0,i),k);
                int right = longestSubstring(s.substr(i+1), k);
                return max(left,right);
            }
        }
        return s.size();
    }
};