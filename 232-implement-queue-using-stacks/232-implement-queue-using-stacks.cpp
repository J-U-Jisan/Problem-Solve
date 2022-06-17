class MyQueue {
private:
    stack<int>fst,snd;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        fst.push(x);
    }
    
    int pop() {
        while(!fst.empty()){
            snd.push(fst.top());
            fst.pop();
        }
        
        int val = snd.top();
        snd.pop();
        while(!snd.empty()){
            fst.push(snd.top());
            snd.pop();
        }
        
        return val;
    }
    
    int peek() {
        while(!fst.empty()){
            snd.push(fst.top());
            fst.pop();
        }
        
        int val = snd.top();
        while(!snd.empty()){
            fst.push(snd.top());
            snd.pop();
        }
        
        return val;
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