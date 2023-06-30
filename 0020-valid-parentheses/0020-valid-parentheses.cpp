class Solution {
public:
    
    bool isMatching(stack<int> &st, char c){
        if(c=='}' && st.top()=='{'){
            return true;
        }else if(c==')' && st.top()=='(')
            return true;
        else if(c==']' && st.top()=='[')
            return true;
        else return false;
    }
    bool isValid(string s) {
        
        
        int i=0;
        stack<int> st;
        while(i<s.size()){
            
            if(!st.empty() && isMatching(st, s[i])){
                st.pop();
            }else st.push(s[i]);
            i++;
        }
        
        return st.empty();
    }
};