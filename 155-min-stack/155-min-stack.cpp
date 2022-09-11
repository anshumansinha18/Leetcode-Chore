class MinStack {
    int *arr;
    int topi;
    int size;
    int* min_pos;
    int i;
    int minima;
public:
    MinStack() {
        topi=-1;
        size = 300001;
        arr = new int[size];
        i=-1;
        minima = topi;
        min_pos = new int[size];
    }
    
    void push(int val) {
        if(topi==size-1)
            return;
        topi++;
        arr[topi] = val;
        
        if(minima == -1 || val < arr[minima])
        {
            minima = topi;
            i++;
            min_pos[i] = minima;
        }
    }
    
    void pop() {
        if(topi==-1)
            return;
        
        topi--;
        if(minima > topi)
        {
            i--;
            minima =  topi==-1?topi:min_pos[i];
        }
        
        
    }
    
    int top() {
        return arr[topi];
    }
    
    int getMin() {
        return arr[minima];
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