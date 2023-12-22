class Solution {
public:
    
    bool isOperator(string c){
        return c=="+" || c=="-" || c=="*" || c=="/";
    }
    
    int performOp(stack<int>& st, string op){
        int second = st.top();
        st.pop();
        int first = st.top();
        st.pop();
        
        if(op=="+") return first+second;
        else if(op=="-") return first-second;
        else if(op=="*") return first*second;
        else if(op=="/") return first/second;
        else return -1;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(isOperator(tokens[i])){
                int result = performOp(st, tokens[i]);
                st.push(result);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};