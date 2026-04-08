class Solution {
public:
    int countKeyChanges(string s) {
        int count =0;
        for(int i=1;i<s.size();i++){
            char c = tolower(s[i]);
            if(c!= tolower(s[i-1]) ){
                count++;
            }
       } 
       return count;
    }
};