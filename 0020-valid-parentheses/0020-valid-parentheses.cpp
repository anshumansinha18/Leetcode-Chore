class Solution {
public:
    
    bool check(stack<int>& st, char s){
        return !st.empty() &&
               ((st.top()=='(' && s==')') || 
               (st.top()=='{' && s=='}') ||
               (st.top()=='[' && s==']'));
    }
    bool isValid(string s) {
        stack<int> st;
        
        for(int i=0;i<s.size();i++){
              
                if(check(st, s[i])) st.pop();
                else st.push(s[i]);
            }
        
        
        return st.empty();
    }
};