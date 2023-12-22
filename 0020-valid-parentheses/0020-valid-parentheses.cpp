class Solution {
public:
    
    bool isOpening(char c){
        return c=='(' || c=='[' || c=='{';
    }
    
    bool isMatching(char x, char y){
        if(x=='}' && y=='{') return true;
        else if(x==']' && y=='[') return true;
        else if(x==')' && y=='(') return true;
        else return false;
    }
    bool isValid(string s) {
        
        int n=s.size();
        
        stack<char> st;
        
        for(int i=0;i<n;i++){
            if(isOpening(s[i])){
                st.push(s[i]);
            }else{
                if(!st.empty() && isMatching(s[i], st.top())){
                    st.pop();
                }else st.push(s[i]);
            }
        }
        
        return st.empty();
    }
};