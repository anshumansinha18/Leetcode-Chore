class Solution {
public:
    int size;
    int top;
    char *arr;
    
    void initializeStack(int size)
    {
        this->size = size;
        top = -1;
        arr = new char[size];
    }
    
    void push(int data){
        if(top+1==size)
            return;
        top++;
        arr[top] = data;
    }
    
    void pop(){
        if(top==-1)
            return;
        top--;
    }
    
    char peek(){
        return arr[top];
    }
    
    bool isEmpty(){
        return top==-1;
    }
    
    bool isValid(string s) {
        
        initializeStack(10001);
        
        for(int i=0;i<s.size();i++)
        {
            if(isEmpty())
                push(s[i]);
            else if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                push(s[i]);
            else if(s[i]==')' && peek()=='(')
                pop();
            else if(s[i]==']' && peek()=='[')
                pop();
            else if(s[i]=='}' && peek()=='{')
                pop();
            else
                push(s[i]);
        }
        
        
        if(isEmpty())
            return true;
        else
            return false;
    }
};