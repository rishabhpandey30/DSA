class MyStack {
public:
    queue<int> qt;
    MyStack() {
    }
    
    void push(int x) {
        qt.push(x);
        int s =qt.size();
        for(int i=0;i<s-1;i++){
            qt.push(qt.front());
            qt.pop();
        }
    }
    
    int pop() {
        int top = qt.front();
        qt.pop();
        return top;
    }
    
    int top() {
       return qt.front();
    }
    
    bool empty() {
        return qt.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */