class Solution {
public:
    
    void generate(string s, vector<string>& res, int open, int close, int n){
        if(open==n && close==n){
            res.push_back(s);
            return;
        }
        
        if(open==close){
            generate(s+'(', res, open+1, close, n);
        }else if(open==n){
            generate(s+')', res, open, close+1, n);
        }else{
            generate(s+'(', res, open+1, close, n);
            generate(s+')', res, open, close+1,  n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
       generate("(", res, 1, 0, n);    
       return res;
    }
};