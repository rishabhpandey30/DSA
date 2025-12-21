class Solution {
public:

    void create(string digits , int idx, string temp, vector<string>&ans,unordered_map<char, string> mp){
        if(idx >= digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            create(digits,idx+1, temp,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string>ans;
       if(digits.size()==0){
        return {};
       }
       unordered_map<char, string> mp ={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
       };
        create(digits, 0, "", ans, mp); 
        return ans;
    }
};