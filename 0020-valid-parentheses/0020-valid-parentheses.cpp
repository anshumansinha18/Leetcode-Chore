class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m;
        m[')']='(';
        m['}']='{';
        m[']']='[';
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()==m[s[i]])
               st.pop();
            else st.push(s[i]);
        }
        
        return st.empty();
    }
};