class Solution {
    vector<string> result;
public:
    
    void addBrackets(string s, int open, int close, int n){
        if(open==n && close==n){
            result.push_back(s);
            return;
        }else if(open==n){
            addBrackets(s+')', open, close+1, n);
        }else if(close<open){
            addBrackets(s+'(', open+1, close, n);
            addBrackets(s+')', open, close+1, n);
        }else if(open==close){
            addBrackets(s+'(', open+1, close, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        addBrackets("", 0, 0,n);
        return result;
    }
};