class Solution {
public:
    void generate(int n, string curr , vector<string>&r){
        if(curr.size()==n){
            r.push_back(curr);
            return;
        }
        
        if(curr.empty()|| curr.back()!= '0'){
            generate(n,curr+"0", r);
        }
        generate(n, curr+"1",r);

    }
    vector<string> validStrings(int n) {
        vector<string> r;
        generate(n,"",r);
        return r;
    }
};