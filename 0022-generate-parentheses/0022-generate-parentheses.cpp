class Solution {
public:
    bool valid(string s){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
                if(count<0){
                    return 1;
                }
            }
        }
        return count;
    }
    void create(int n, string s, vector<string>& str ){
       if(s.size()==(2*n)){
        if(!valid(s)){
            str.push_back(s);
        }
        return;
       }
       s.push_back('(');
       create(n,s,str);
       s.pop_back();
       s.push_back(')');
       create(n,s,str);
       s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> str;
        create(n, "", str);
        return str;
    }
};