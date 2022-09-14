class MinStack {
    int size;
    int *arr;
    int *min_stack;
    int topi;
public:
    MinStack() {
        size = 30000;
        topi = -1;
        arr = new int[size];
        min_stack = new int[size];
    }
    
    void push(int val) {
        if(topi==size-1)
            return;
        
        topi++;
        if(topi!=0 && min_stack[topi-1]<val)
            min_stack[topi] = min_stack[topi-1];
        else
            min_stack[topi] = val;
        
        arr[topi] = val;
    }
    
    void pop() {
        if(topi == -1)
            return;
        
        topi--;
    }
    
    int top() {
      
        return arr[topi];
    }
    
    int getMin() {
     
        return min_stack[topi];
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