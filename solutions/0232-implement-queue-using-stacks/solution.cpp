#include<queue>
class MyQueue {
public:
queue<int> m;
    MyQueue() {
        
    }
    
    void push(int x) {
        m.push(x);
    }
    
    int pop() {
        int val=m.front();m.pop();
        return val;
    }
    
    int peek() {
        return m.front();
    }
    
    bool empty() {
        return m.empty();
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
