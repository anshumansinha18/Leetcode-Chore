class MinStack {
    stack<int> st;
    stack<int> normalStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        normalStack.push(val);
        stack<int> temp;
        while(!st.empty() && val>st.top()){
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        st.push(val);
        while(!temp.empty()){
            int x = temp.top();
            temp.pop();
            st.push(x);
        }
    }
    
    void pop() {
        int topElem = normalStack.top();
        normalStack.pop();
        stack<int> temp;
        while(!st.empty() && st.top()!=topElem){
            int x = st.top();
            st.pop();
            temp.push(x);
        }
        st.pop();
        while(!temp.empty()){
            int x = temp.top();
            temp.pop();
            st.push(x);
        }
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return st.top();
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