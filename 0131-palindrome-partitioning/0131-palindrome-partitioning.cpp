class Solution {
public:
    void create(string s, int idx,vector<vector<string>>& ans, vector<string> &temp ){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx, i-idx +1));
                create(s,i+1, ans,temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        create(s,0,ans,temp);
        return ans;
    }
};