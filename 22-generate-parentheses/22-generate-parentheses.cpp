class Solution {
public:
    
    void funct(string s, int open, int close, vector<string>& res, int n)
    {
        if(close==n)
        {
            res.push_back(s);
            return;
        }
        
        if(open<n)
        {
            if(open>close)
            {
                funct(s+'(', open+1, close, res, n);
                funct(s+')', open, close+1, res, n);
                
            }
            else
                funct(s+'(', open+1, close, res, n);
        }
        else
            funct(s+')', open, close+1, res, n);
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string s="";
        funct(s, 0, 0, res, n);
        return res;
    }
};