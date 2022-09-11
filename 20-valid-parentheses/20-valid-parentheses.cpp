class Solution {
    int top;
    char *arr;
    int size;
public:
    
    void initializeStack(int s)
    {
        size = s;
        top = -1;
        arr = new char[s];
    }
    
    void push(char num){
        if(top==size-1)
            return;
        arr[++top] = num;
    }
    
    void pop()
    {
        if(top==-1)
            return;
        top--;
    }
    
    char peek(){
        if(top==-1)
            return -1;
        return arr[top];
    }
    
    bool isEmpty(){
        if(top==-1)
            return true;
        return false;
    }
    
    bool isValid(string s) {
        
        initializeStack(10001);
        
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==']' && peek() == '[')
                pop();
            else if(s[i]==')' && peek() == '(')
                pop();
            else if(s[i]=='}' && peek() == '{')
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