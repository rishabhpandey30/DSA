class Solution {
public:
    // bool valid(string s){
    //     int count=0;
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]=='('){
    //             count++;
    //         }
    //         else{
    //             count--;
    //             if(count<0){
    //                 return 1;
    //             }
    //         }
    //     }
    //     return count;
    // }
    // void create(int n, string s, vector<string>& str ){
    //    if(s.size()==(2*n)){
    //     if(!valid(s)){
    //         str.push_back(s);
    //     }
    //     return;
    //    }
    
    //    create(n,s+'(',str);

    //    create(n,s+')',str);

    // }

    //Method -2 
    void create(int n, string s, vector<string>& str , int open, int close){
        if(s.size()==2*n){
            str.push_back(s);
            return;
        }

        if(open<n){
            create(n,s+"(",str,open+1,close);
        }
        if(close<open){
            create(n,s+")",str, open, close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> str;
        int open =0;
        int close =0;
        create(n, "", str,open,close);
        return str;
    }
};