class Solution {
public:
    
    int performOp(int x, int y, string c){
        if(c=="+")
            return x+y;
        else if(c=="-")
            return x-y;
        else if(c=="*")
            return x*y;
        else
            return x/y;
    }
    int evalRPN(vector<string>& tokens) {
        
        int i=0;
        int n = tokens.size();
        stack<int> st;
        while(i<n){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(performOp(y,x,tokens[i]));
            }else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        
        return st.top();
    }
};