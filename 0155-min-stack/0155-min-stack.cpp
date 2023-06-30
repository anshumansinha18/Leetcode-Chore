class MinStack {
    int *arr1;
    int *arr2;
    int top1;
    int top2;
    int size;
public:
    MinStack() {
        size=3*100000;
        arr1 = new int[size];
        arr2=new int[size];
        top1=-1;
        top2=-1;
    }
    
    void push(int val) {
        if(top1==size-1){
            return;
        }
        
        top1++;
        arr1[top1]=val;
        
        if(top2==-1){
            arr2[++top2]=val;
        }else{
            if(val<=arr2[top2]){
                arr2[++top2]=val;
            }
        }
        
    }
    
    void pop() {
         if(top1==-1)
             return;
        
        if(arr1[top1]==arr2[top2]){
            top2--;
        }
        
        top1--;
    }
    
    int top() {
        return arr1[top1];
    }
    
    int getMin() {
        return arr2[top2];
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