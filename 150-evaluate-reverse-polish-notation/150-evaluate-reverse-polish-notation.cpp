class Solution {
    long long int *arr;
    int size;
    int top;
public:
    
    void initializeStack()
    {
        size = 10000;
        top = -1;
        arr = new long long int[size];
    }
    
    void push(long long int val)
    {
        if(top == size-1)
            return;
        
        top++;
        arr[top] = val;
    }
    
    void pop()
    {
        if(top == -1)
            return;
        top--;
    }
    
    long long int peek()
    {
        if(top == -1)
            return INT_MIN;
        return arr[top];
    }
    
    long long int operation(string x, int first, int second)
    {
        if(x == "+")
            return first + second;
        else if(x == "-")
            return first - second;
        else if(x == "*")
            return (long long int)first * second;
        else
            return first / second;
    }
    
    bool isOperator(string s)
    {
        if(s == "+" || s == "-" || s=="*" || s=="/")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        initializeStack();
        
        vector<string> &v = tokens;
        
        int n = tokens.size();
        
        for(int i=0;i<n;i++)
        {
            if(!isOperator(v[i]))
            {
                push(stoi(v[i]));
            }
            else
            {
                long long int second = peek();
                pop();
                long long int first = peek();
                pop();
                long long int res = operation(v[i], first, second);
                push(res);
            }
        }
        
        return peek();
        
    }
};