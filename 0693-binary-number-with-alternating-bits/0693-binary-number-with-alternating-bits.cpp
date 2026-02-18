class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        
        while(n!=1){
            int digit = n%2;
            string str = to_string(digit);
            s += str;
            n = n/2;
        }
        s+='1';
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                return false;
            }
        }
        return true;
    }
};