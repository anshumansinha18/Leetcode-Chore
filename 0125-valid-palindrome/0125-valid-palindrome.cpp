class Solution {
public:
    
    bool isAlphaNumeric(char c){
        if((c >='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'))
            return true;
        else
            return false;
    }
    
    
    bool isPalindrome(string s) {
        
        string res = "";
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(isAlphaNumeric(s[i]))
                res+= (char)tolower(s[i]);
        }
        
        cout<<res;
        int start=0;
        int end=res.size()-1;
        while(start<end){
            if(res[start]!=res[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
        
        
    }
};