class MyQueue {
private:
    stack<int>fst,snd;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!fst.empty()){
            snd.push(fst.top());
            fst.pop();
        }
        fst.push(x);
        while(!snd.empty()){
            fst.push(snd.top());
            snd.pop();
        }
    }
    
    int pop() {
        int val = fst.top();
        fst.pop();
        
        return val;
    }
    
    int peek() {
        return fst.top();;
    }
    
    bool empty() {
        return fst.empty();
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