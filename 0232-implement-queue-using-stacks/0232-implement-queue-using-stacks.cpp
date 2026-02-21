class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        int s = s1.size();
        for(int i=0;i<s;i++){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        s = s2.size();
        for(int i=0;i<s;i++){
            s1.push(s2.top());
            s2.pop();
        }
        
        
    }
    
    int pop() {
        int a = s1.top();
        s1.pop();
        return a;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */