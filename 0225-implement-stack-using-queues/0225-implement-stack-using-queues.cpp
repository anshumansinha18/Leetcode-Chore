class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty() && q2.empty()) q1.push(x);
        else if(q1.empty()) q2.push(x);
        else if(q2.empty()) q1.push(x);
    }
    
    int pop() {
        if(q1.empty()){
            while(q2.size()!=1){
                int x = q2.front();
                q2.pop();
                q1.push(x);
            }
            int res = q2.front();
            q2.pop();
            return res;
        }else{
            while(q1.size()!=1){
                int x = q1.front();
                q1.pop();
                q2.push(x);
            }
            int res = q1.front();
            q1.pop();
            return res;
        }
    }
    
    int top() {
        if(q1.empty()) return q2.back();
        else return q1.back();
    }
    
    bool empty() {
        return (q1.empty() && q2.empty()) ;
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