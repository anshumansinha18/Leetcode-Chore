class MyStack {
    int active;
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        active=1;
    }
    
    void push(int x) {
        if(active==1){
            q1.push(x);
        }else q2.push(x);
    }
    
    int pop() {
        int res;
        if(active==1){
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            res=q1.front();
            q1.pop();
            active=2;
        }else{
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            res=q2.front();
            q2.pop();
            active=1;
        }
        return res;
    }

    
    int top() {
        if(active==1) return q1.back();
        else return q2.back();
    }
    
    bool empty() {
        if(q1.size()==0 && q2.size()==0) return true;
        else return false;
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