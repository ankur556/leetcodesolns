class MinStack {
public:
stack<pair<int,int>> min;
int idx=0;
stack<int> b;
    MinStack() {
        stack<pair<int,int>>g;
        stack<int>a;
        min=g;
        b=a;
        idx=0;
    }
    
    void push(int val) {    
        if(idx==0){
           min.push({val,++idx}); 
        }
        else{
            if(min.top().first<val){idx++;}
            else{min.push({val,++idx});}
        }
        b.push(val);
    }
    
    void pop() {
        if(idx==min.top().second){min.pop();idx--;}
        else{idx--;}
        b.pop();
    }
    
    int top() {
        return b.top();
    }
    
    int getMin() {
        return min.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
