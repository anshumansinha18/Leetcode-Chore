class Solution {
public:
    
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        
        int i=0,j=0, n = s.size();
        int len=0;
        int res=0;
        for(int i=0;i<n;i++){
            
            if(isVowel(s[i]))
                len++;
            
            if(i-j+1==k){
                res = max(res, len);
                if(isVowel(s[j]))
                    len--;
                j++;
            }
        }
        
        return res;
    }
};