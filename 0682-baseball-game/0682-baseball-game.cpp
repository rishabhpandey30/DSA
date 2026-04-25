class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0;i<operations.size();i++){
            string val = operations[i];
            if(val == "+"){
                if(!st.empty()){
                    int top = st.top();
                    st.pop();
                    int ans = top + st.top();
                    st.push(top);
                    st.push(ans);    
                }
            }
            else if(val == "D"){
                int ans =st.top()*2;
                st.push(ans);
            }
            else if(val == "C"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(stoi(val));
            }
        }
        int sum =0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};