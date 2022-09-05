class Solution {
public:
    
    bool isAlphanumeric(char c)
    {
        return (c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z');
    }
    
 
    bool isUppercase(char c)
    {
        return (c>='A' && c<='Z');
    }
    
    bool checkPalindrome(string p)
    {
        int start = 0;
        int end = p.size()-1;
        
        while(start<end)
        {
            if(p[start++]!=p[end--])
                return false;
        }
        
        return true;
    }
    
    bool isPalindrome(string s) {
          
        string p;
        
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(isAlphanumeric(s[i]))
            {
                if(isUppercase(s[i]))
                    s[i] = char(s[i]+32);
                
                p.push_back(s[i]);
            }
        }
        cout<<p<<endl;
        bool x = checkPalindrome(p);
        return x;
    }
};