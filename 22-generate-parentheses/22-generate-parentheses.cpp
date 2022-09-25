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
                s+='(';
                open++;
                funct(s, open, close, res, n);
                s.pop_back();
                open--;
                s+=')';
                close++;
                funct(s, open, close, res, n);
                
            }
            else
            {
                s+='(';
                open++;
                funct(s, open, close, res, n);
            }
        }
        else
        {
            s+=')';
            close++;
            funct(s, open, close, res, n);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string s="";
        funct(s, 0, 0, res, n);
        return res;
    }
};